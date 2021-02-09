#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

struct polynom {
    static const int N = 11;
    int a[N]{};
};

struct graph {
    int n;
    set<int> g[10];
    graph () {}
    graph(graph const &a) {
        for (int i = 0; i < 10; i++) {
            g[i] = a.g[i];
        }
        n = a.n;
    }
    graph delete_edge(int a, int b) {
        graph res = *this;
        if (res.g[a].find(b) != res.g[a].end()) {
            res.g[a].erase(b);
        }
        if (res.g[b].find(a) != res.g[b].end()) {
            res.g[b].erase(a);
        }
        return res;
    }
    graph comp(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        graph res = *this;
        set<int> set_a = res.g[a];
        set<int> set_b = res.g[b];
        set<int> set;
        for (auto i : set_a)
            set.insert(i);
        for (auto i : set_b)
            set.insert(i);
        for (int i = 0; i < 10; i++) {
            if (res.g[i].find(a) != res.g[i].end()) {
                res.g[i].erase(a);
            }
        }
        for (auto i : set_a) {
            res.g[i].insert(b);
        }
        if (set.find(a) != set.end()) {
            set.erase(a);
        }
        if (set.find(b) != set.end()) {
            set.erase(b);
        }
        res.g[a].clear();
        res.g[b] = set;
        res.n = this->n - 1;
        return res;
    }
};

bool check(graph &g) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += len(g.g[i]);
    }
    return (sum == 0);
}

polynom gen(graph &g) {
    if (check(g)) {
        polynom res;
        res.a[g.n] = 1;
        return res;
    } else {
        int x = -1, y = -1;
        for (int i = 0; i < 10; i++) {
            for (auto j : g.g[i]) {
                x = i;
                y = j;
                break;
            }
            if (x != -1 && y != -1) {
                break;
            }
        }
        graph g1 = g.delete_edge(x, y);
        graph g2 = g.comp(x, y);
        polynom poly1 = gen(g1);
        polynom poly2 = gen(g2);
        for (int i = 0; i < poly1.N; i++) {
            poly1.a[i] -= poly2.a[i];
        }
        return poly1;
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    graph g;
    g.n = n;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.g[a].insert(b);
        g.g[b].insert(a);
    }

    polynom result = gen(g);
    cout << n << "\n";
    int beg = -1;
    for (int i = result.N - 1; i >= 0; i--) {
        if (result.a[i] != 0) {
            beg = i;
            break;
        }
    }
    for (int i = beg; i >= 0; i--) {
        cout << result.a[i] << ' ';
    }
    return 0;
}
