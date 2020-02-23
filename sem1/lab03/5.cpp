#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("telemetry.in", "rt", stdin);
	freopen("telemetry.out", "wt", stdout);
	#endif  //   HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector <string> a;
	string kek = "1";
	for (int i = 0; i < k; i++) {
		kek[0] = '0' + i;
		a.push_back(kek);
	}
	for (int i = 0; i < n - 1; i++) {
		vector <string> b;
		int x = 0;
		for (int j = 0; j < k; j++) {
			if (x % 2 == 1) {
				for (int f = 0; f < len(a); f++) {
					int ind = len(a) - 1 - f;
					string curs = "1";
					curs[0] = '0' + j;
					curs = curs + a[ind];
					b.push_back(curs);
				}
			} else {
				for (auto s : a) {
					string curs = "1";
					curs[0] = '0' + j;
					curs = curs + s;
					b.push_back(curs);
				}
			}
			x++;
		}
		b.swap(a);
	}
	for (auto i : a) {
		cout << i << "\n";
	}
	return 0;
}

