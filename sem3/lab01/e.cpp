#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 1e5 + 10;

unordered_set<int> g[N];
set <int> leafs;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#endif  // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    for (int i = 0; i < n; i++) {
        if (len(g[i]) == 1) {
            leafs.insert(i);
        }
    }
    vector <int> code;
    for (int i = 0; i < n - 2; i++) {
        int v = *leafs.begin();
        int u = *g[v].begin();
        leafs.erase(v);
        g[u].erase(v);
        g[v].erase(u);
        if (len(g[u]) == 1) {
            leafs.insert(u);
        }
        code.push_back(u);
    }
    for (int i : code) {
        cout << i + 1 << ' ';
    }
    return 0;
}
