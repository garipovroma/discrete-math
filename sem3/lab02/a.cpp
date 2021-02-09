#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("schedule.in", "rt", stdin);
    freopen("schedule.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a), [](const pair<int, int> &a, const pair<int, int> &b){
        return (a.first < b.first || (a.first == b.first && a.second > b.second));
    });
    int time = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (time < a[i].first) {
            time++;
        } else {
            sum += a[i].second;
        }
    }
    cout << sum;
    return 0;
}
