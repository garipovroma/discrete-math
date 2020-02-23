#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

int main() {
	#ifdef HOME
//	freopen("input.txt", "rt", stdin);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector <vector <int>> a(k);
	for (int i = 0; i < k; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x >= 0)  {
				sum++;
			}
			a[i].push_back(x);
		}
	}
	int num = 2228;
	vector <int> v(n, 0);
	while(num--) {
		int res = 1;
		for (int i = 0; i < k; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] < 0) continue;
				if (a[i][j] == v[j])
					sum++;
			}
			sum = min(sum, 1);
			res *= sum;
		}
		if (res > 0) {
			cout << "NO";
			return 0;
		}
		for (int i = 0; i < k; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] < 0) continue;
				if (a[i][j] == v[j])
					sum++;
			}
			sum = min(sum, 1);
			if (sum == 0) {
				for (int j = 0; j < n; j++) {
					if (a[i][j] == 1 && v[j] == 1) {
						cout << "YES";
						return 0;
					}
					if (a[i][j] == 1 && v[j] == 0) {
						v[j] = 1;
						break;
					}

				}
			}
		}
	}
	cout << "YES";
	return 0;
}
