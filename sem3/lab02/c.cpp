#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 1000;

vector <int> g[N];
vector <int> mt;
vector <int> r_mt;
vector <bool> used;

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int i : g[v]) {
        if (mt[i] == -1 || dfs(mt[i])) {
            mt[i] = v;
            r_mt[v] = i;
            return true;
        }
    }
    return false;
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("matching.in", "rt", stdin);
    freopen("matching.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector <pair<int, int>> vertexes;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vertexes.emplace_back(w[i], i);
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            y--;
            g[i].push_back(y);
        }
    }
    sort(all(vertexes));
    reverse(all(vertexes));
    used.resize(n, false);
    mt.resize(n, -1);
    r_mt.resize(n, -1);
    for (auto kek : vertexes) {
        int i = kek.second;
        used.assign(n, false);
        dfs(i);
    }
    for (int i = 0; i < n; i++) {
        cout << r_mt[i] + 1 << ' ';
    }
    return 0;
}
