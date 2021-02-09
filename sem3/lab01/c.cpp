#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(1, 0);

    for (int i = 1; i < n; i++) {
        int l = 0, r = i + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            cout << 1 << ' ' << a[m - 1] + 1 << ' ' << i + 1 << endl;
            string query_res;
            cin >> query_res;
            if (query_res == "YES") {
                l = m;
            } else {
                r = m;
            }
        }
        a.insert(a.begin() + l, i);
    }
    cout << 0 << " ";
    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}