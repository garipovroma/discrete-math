#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 10000;

vector <int> g[N];

vector <int> colors;
vector <int> was;
vector <bool> used;

void dfs(int v, int mx) {
    used[v] = true;
    for (int i : g[v]) {
        if (!used[i]) {
            for (int j = 0; j < mx; j++) {
                was[j] = -1;
            }
            for (int j : g[i]) {
                if (colors[j] != -1) {
                    was[colors[j]] = 1;
                }
            }
            int cur = -1;
            for (int j = 0; j < mx; j++) {
                if (was[j] == -1) {
                    cur = j;
                    break;
                }
            }
            colors[i] = cur;
            dfs(i, mx);
        }
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
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, len(g[i]));
    }
    if (mx % 2 == 0) {
        mx++;
    }
    colors.resize(n, -1);
    was.resize(n, -1);
    used.resize(n, false);
    colors[0] = 0;
    dfs(0, mx);
    cout << mx << "\n";
    for (int i = 0; i < n; i++) {
        cout << colors[i] + 1 << "\n";
    }
    return 0;
}
