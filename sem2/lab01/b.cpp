#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 129;

bool term[N];
unordered_map <char, vector<int>> g[N];

int main() {
    #ifdef HOME
    freopen("input.txt", "rt", stdin);
    #else
    freopen("problem2.in", "rt", stdin);
    freopen("problem2.out", "wt", stdout);
    #endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    string s;
    cin >> s >> n >> m >> k;
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
        g[a][c].push_back(b);
    }
    unordered_set <int> cur_layer;
    cur_layer.insert(0);
    unordered_set <int> nw_layer;
    for (int i = 0; i < len(s); i++) {
        for (auto j : cur_layer) {
            char c = s[i];
            for (auto x : g[j][c]) {
                nw_layer.insert(x);
            }
        }
        cur_layer.clear();
        nw_layer.swap(cur_layer);
    }
    for (auto i : cur_layer) {
        if (term[i]) {
            cout << "Accepts";
            return 0;
        }
    }
    cout << "Rejects";
    return 0;
}