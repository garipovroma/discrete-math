#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = len(s);
    unordered_map <string, int> kek;
    set <string> was;
    string willNeverUsedAfterThisFor = "1";
    for (char c = 'a'; c <= 'z'; c++) {
        willNeverUsedAfterThisFor[0] = c;
        kek[willNeverUsedAfterThisFor] = (int)(c - 'a');
        //was.insert(willNeverUsedAfterThisFor);
    }
    string t = "1";
    t[0] = s[0];
    int num = 26;
    string tt;
    for (int i = 1; i < n; i++) {
        char c = s[i];
        tt = t;
        tt.push_back(c);
        //cout << tt << ' ' << kek[tt] << " : ";
        if (kek[tt] > 0) {
            t.push_back(c);
        } else {
            cout << kek[t] << ' ';
            //was.insert(tt);
            kek[tt] = num++;
            t = "1";
            t[0] = c;
        }
        //cout << endl;
    }
    cout << kek[t];
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("lzw.in", "rt", stdin);
	freopen("lzw.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
} 
