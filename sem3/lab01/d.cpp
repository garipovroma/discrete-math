#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 1001;

bool g[N][N];

vector <int> a;

int main() {
    #ifdef HOME
        freopen("input.txt", "rt", stdin);
    #endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string tmp;
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < i; j++) {
            if (tmp[j] == '1') {
                g[i][j] = true;
            } else {
                g[j][i] = true;
            }
        }
    }
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    a[n - 2] = n - 1;
    a[n - 1] = n - 2;
    while (clock() < 0.99 * CLOCKS_PER_SEC) {
        vector <int> kektor(1, a[0]);
        for (int i = 1; i < len(a); i++) {
            int pos = 0;
            int cur_vertex = a[i];
            for (int j = 0; j < len(kektor) && g[kektor[j]][cur_vertex]; j++) {
                pos = j + 1;
            }
            kektor.insert(kektor.begin() + pos, cur_vertex);
        }
        bool flag = true;
        for (int i = 0; i < len(kektor) - 1; i++) {
            int x = kektor[i];
            int y = kektor[i + 1];
            flag = (flag && g[x][y]);
        }
        flag = (flag && g[kektor.back()][kektor.front()]);
        a = kektor;
        if (flag) {
            break;
        }
        shuffle(all(a), std::mt19937(std::random_device()()));
    }
    for (int i : a) {
        cout << i + 1 << ' ';
    }
    return 0;
}
