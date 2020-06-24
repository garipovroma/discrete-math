#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 1e5 + 10;
const ll M = 1e9 + 7;

struct kek{
    bool term[N];
    unordered_map <char, int> g[N];
    unordered_map <char, int> tg[N];
    bool att[N];
    int n, m, k;
    kek(int n_, int m_, int k_) {
        n = n_;
        m = m_;
        k = k_;
        for (int i = 0; i < n_; i++) {
            for (char c = 'a'; c <= 'z'; c++)
                    g[i][c] = -1;
        }
    }

    void read() {
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            x--;
            term[x] = true;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            char c;
            cin >> a >> b >> c;
            a--;
            b--;
            g[a][c] = b;
            tg[b][c] = a;
        }
    }
    void rev_dfs(int v, vector <bool> &used) {
        used[v] = true;
        for (auto i : tg[v]) {
            if (!used[i.second]) {
                rev_dfs(i.second, used);
            }
        }
    }

    void calc_attainability() {
        vector <bool> used(n, false);
        for (int i = 0; i < n; i++) {
            if (term[i] && !used[i]) {
                rev_dfs(i, used);
            }
        }
        for (int i = 0; i < n; i++) {
            att[i] = used[i];
        }
    }

    void dfs(int v, vector <bool> &used, vector <int> &res) {
        used[v] = true;
        for (char c = 'a'; c <= 'z'; c++) {
            int x = g[v][c];
            if (x == -1) continue;
            if (!used[x]) {
                dfs(x,  used, res);
            }
        }
        res.push_back(v);
    }
    vector<int> get_ord() {
        vector <bool> used(n, false);
        vector <int> sz(n, false);
        vector <int> ord;
        dfs(0, used, ord);
        return ord;
    }
};

bool check_vert(kek &a, kek & b, int x, int y, vector <int> &ord1, vector <int> &ord2) {
    int v = ord1[x];
    int u = ord2[y];
    bool ok = true;
    for (char c = 'a'; c <= 'z'; c++) {
        if (a.g[v][c] == -1 && b.g[u][c] != -1) {
            ok = false;
        }
        if (a.g[v][c] != -1 && b.g[u][c] == -1) {
            ok = false;
        }
    }
    return ((a.term[v] == b.term[u]) && ok);
}


int main() {
    #ifdef HOME
    freopen("input.txt", "rt", stdin);
    #else
    freopen("isomorphism.in", "rt", stdin);
    freopen("isomorphism.out", "wt", stdout);
    #endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    kek v1 = kek(n, m, k);
    v1.read();
    cin >> n >> m >> k;
    kek v2 = kek(n, m, k);
    v2.read();
    v1.calc_attainability();
    v2.calc_attainability();
    vector <int> ord1 = v1.get_ord();
    vector <int> ord2 = v2.get_ord();
    bool res = true;
    for (int i = 0; i < n; i++) {
        if (!check_vert(v1, v2, i, i, ord1, ord2)) {
            res = false;
            break;
        }
    }
    if (res)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}