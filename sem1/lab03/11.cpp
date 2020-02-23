#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("subsets.in", "rt", stdin);
	freopen("subsets.out", "wt", stdout);
	#endif  //  HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector <string> kek;
	for (int i = 0; i < (1 << n); i++) {
		string s;
		for (int j = n - 1; j >= 0; j--) {
			int b = (i >> j) & 1;
			if (b == 1)
				s.push_back(j + '0');
		}
		reverse(all(s));
		kek.push_back(s);
	}
	sort(all(kek));
	for (auto i : kek) {
		for (auto j : i) {
			cout << j - '0' + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}