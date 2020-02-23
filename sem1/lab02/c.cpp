#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = len(s);
    vector <char> ord;
    for (char c = 'a'; c <= 'z'; c++)
        ord.push_back(c);
    for (char i : s) {
        /*for (auto j : ord)
            cout << j << ' ';
        cout << endl;*/
        for (int j = 0; j < len(ord); j++) {
            if (ord[j] == i) {
                cout << j + 1 << ' ';
                break;
            }
        }
        vector <char> nword;
        nword.push_back(i);
        for (int j = 0; j < len(ord); j++) {
            if (ord[j] != i)
                nword.push_back(ord[j]);
        }
        ord = nword;
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("mtf.in", "rt", stdin);
	freopen("mtf.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}