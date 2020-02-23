#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 1e5;

unordered_set <int> g[N];
vector <int> ord;
vector <bool> used;
vector <int> d;

void tops(int v) {
    used[v] = true;
    for (int i : g[v])
        if (!used[i])
            tops(i);
    ord.push_back(v);
}

void gfs(int v, int depth) {
    used[v] = true;
    d[v] = depth;
    for (int i : g[v]) {
        if (!used[i])
            gfs(i, depth + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set <pair<ll, int>> s;
    for (int i = 0; i < n; i++)
        s.insert({a[i], i});
    int ind = n;
    while(len(s) >= 2) {
        pair <ll, int> v1 = *s.begin();
        s.erase(*s.begin());
        pair <ll, int> v2 = *s.begin();
        s.erase(*s.begin());
        ll sum = v1.first + v2.first;
        int id = ind++;
        g[id].insert(v1.second);
        g[id].insert(v2.second);
        s.insert({sum, id});
    }
    used.resize(ind, false);
    for (int i = 0; i < ind; i++)
        if (!used[i])
            tops(i);
    reverse(all(ord));
    d.resize(ind, 0);
    used.assign(n, false);
    for (int i : ord) {
        if (!used[i]) {
            gfs(i, 0);
        }
    }
    /* for (int i = 0; i < ind; i++)
        cout << d[i] <<  ' '; */
    ll ans = 0;
    /*cout << endl;*/
    for (int i = 0; i < n; i++)
        ans += 1ll * d[i] * 1ll * a[i];
    cout << ans;
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("huffman.in", "rt", stdin);
	freopen("huffman.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}