#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 1e5 + 100;

bool term[N];
unordered_map <char, int> g[N];

int main() {
    #ifdef HOME
    freopen("input.txt", "rt", stdin);
    #else
    freopen("problem1.in", "rt", stdin);
    freopen("problem1.out", "wt", stdout);
    #endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    string s;
    cin >> s >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            g[i][c] = -1;
        }
    }
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
    }
    int cur = 0;
    int ns = len(s);
    for (int i = 0; i < ns; i++) {
        char c = s[i];
        if (g[cur][c] == -1) {
            cout << "Rejects";
            return 0;
        }
        cur = g[cur][c];
    }
    if (term[cur]) {
        cout << "Accepts";
    } else {
        cout << "Rejects";
    }
    return 0;
}