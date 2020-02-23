#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

void kekshift(string &s) {
    char x = s[0];
    int n = len(s);
    for (int i = 0; i < n - 1; i++)
        s[i] = s[i + 1];
    s[n - 1] = x;
}

void solve() {
    string s;
    cin >> s;
    vector <string> kek;
    kek.push_back(s);
    for (int i = 0; i < len(s) - 1; i++) {
        kekshift(s);
        kek.push_back(s);
    }
    sort(all(kek));
    for (auto i : kek)
        cout << i[len(i) - 1];
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("bwt.in", "rt", stdin);
	freopen("bwt.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}