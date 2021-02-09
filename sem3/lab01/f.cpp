#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 1e5 + 10;

vector <pair<int, int>> edges;
vector <int> deg;
set <int> vert;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#endif  // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> code(n - 2);
    deg.assign(n, 0);
    for (int i = 0; i < n; i++) {
        vert.insert(i);
    }
    for (int i = 0; i < n - 2; i++) {
        cin >> code[i];
        code[i]--;
        deg[code[i]]++;
        if (deg[code[i]] == 1) {
            vert.erase(code[i]);
        }
    }
    for (int i = 0; i < n - 2; i++) {
        int v = *vert.begin();
        int u = code[i];
        vert.erase(v);
        edges.emplace_back(v, u);
        deg[u]--;
        if (deg[u] == 0) {
            vert.insert(u);
        }
    }
    edges.emplace_back(*vert.begin(), n - 1);
    for (auto i : edges) {
        cout << i.first + 1 << ' ' << i.second + 1 << "\n";
    }
    return 0;
}
