#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 5e5 + 228;

struct DSU {
    int p[N], sz[N];
    DSU() {
        for (int i = 0; i < N; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int get_p(int v) {
        if (p[v] == v) {
            return v;
        } else {
            return p[v] = get_p(p[v]);
        }
    }
    bool un(int x, int y) {
        x = get_p(x);
        y = get_p(y);
        if (x == y) {
            return false;
        }
        if (sz[x] > sz[y]) { // x <= y
            swap(x, y);
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }
};

struct edge {
    int from, to, id;
    long double cost;
    edge() {}
    edge (int _from, int _to, long double _cost, int _id) {
        from = _from;
        to = _to;
        cost = _cost;
        id = _id;
    }
};

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("destroy.in", "rt", stdin);
    freopen("destroy.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    long double s;
    cin >> n >> m >> s;
    vector <edge> edges;
    long double sum = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        long double c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.emplace_back(a, b, c, i);
        sum += c;
    }
    sort(all(edges), [](const edge &a, const edge &b) {
        return (a.cost > b.cost);
    });
    long double x = sum - s;
    DSU d;
    vector <bool> was(m, false);
    long double cur_cost = 0;
    for (auto edge: edges) {
        if (cur_cost >= x && d.sz[d.get_p(0)] == n) {
            break;
        }
        int a = edge.from;
        int b = edge.to;
        if (d.un(a, b)) {
            cur_cost += edge.cost;
            was[edge.id] = true;
        }
    }
    for (auto edge: edges) {
        if (cur_cost >= x && d.sz[d.get_p(0)] == n) {
            break;
        }
        if (!was[edge.id]) {
            cur_cost += edge.cost;
            was[edge.id] = true;
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (!was[i]) {
            count++;
        }
    }
    cout << count << "\n";
    for (int i = 0; i < m; i++) {
        if (!was[i]) {
            cout << i + 1 << ' ';
        }
    }
    return 0;
}
