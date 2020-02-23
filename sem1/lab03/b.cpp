#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("gray.in", "rt", stdin);
	freopen("gray.out", "wt", stdout);
	#endif  //  HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector <string> s;
	s.push_back("0");
	s.push_back("1");
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		vector <string> nw;
		for (auto x : s) {
			string cur = "0" + x;
			nw.push_back(cur);
		}
		for (int j = len(s) - 1; j >= 0; j--) {
			string cur = "1" + s[j];
			nw.push_back(cur);
		}
		nw.swap(s);
	}
	for (auto i : s) {
		cout << i << "\n";
	}
	return 0;
}