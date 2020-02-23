#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

vector <int> get_next(vector <int> a, int n, int k) {
    vector <bool> was(n + 1);
    for (int i : a)
        was[i] = true;
    int mx = -1;
    for (int i = n; i >= 1; i--) {
        if (!was[i]) {
            mx = i;
            break;
        }
    }
    int id = -1;
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] < mx) {
            bool localWas = false;
            for (int j = a[i] + 1; j <= n; j++) {
                if (!was[j]) {
                    mx = j;
                    localWas = true;
                    break;
                }
            }
            for (int j = i; j < k; j++)
                was[a[j]] = false;
            was[a[i]] = false;
            was[mx] = true;
            a[i] = mx;
            id = i + 1;
            break;
        }
        //was[a[i]] = false;
        //mx = max(mx, a[i]);
    }
    if (id == -1) {
        return vector <int>(1, -1);
    }
    vector <int> mas;
    for (int i = mx; i <= n; i++) {
        if (!was[i]) {
            mas.push_back(i);
        }
    }
    int pos = 0;
    for (int i = id; i < k; i++) {
        a[i] = mas[pos++];
    }
    sort(all(a));
    return a;

}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("nextchoose.in", "rt", stdin);
	freopen("nextchoose.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    vector <int> b = get_next(a, n, k);
    for (int i : b)
        cout << i << ' ';
    return 0;
}
