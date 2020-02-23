#include <bits/stdc++.h>

using namespace std;

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("allvectors.in", "rt", stdin);
	freopen("allvectors.out", "wt", stdout);
	#endif  //  HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = n - 1; j >= 0; j--) {
			int b = (i >> j) & 1;
			cout << b;
		}
		cout << "\n";
	}
	return 0;
}