#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

string minus1(string s) {
	int n = len(s);
	int id = n - 1;
	while (id >= 0 && s[id] != '1') {
		id--;
	}
	s[id] = '0';
	for (int i = id + 1; i < n; i++)
		s[i] = '1';
	return s;
}

string plus1(string s) {
	int n = len(s);
	vector <int> x(n);
	for (int i = 0; i < n; i++)
		x[i] = s[i] - '0';
	x[n - 1]++;
	int cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		x[i] = x[i] + cur;
		cur = x[i] / 2;
		x[i] %= 2;
	}
	string res;
	for (int i = 0; i < n; i++)
		res.push_back(x[n - 1 - i] + '0');
	if (cur != 0)
		return "-";
	reverse(all(res));
	return res;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("nextvector.in", "rt", stdin);
	freopen("nextvector.out", "wt", stdout);
	#endif  //  HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = len(s);
	bool zero = true;
	for (auto c : s)
		if (c != '0')
			zero = false;
	if (zero) {
		cout << "-\n";
		for (int i = 0; i < n - 1; i++)
			cout << 0;
		cout << 1;
		return 0;
	}
	cout << minus1(s) << "\n" << plus1(s);
	return 0;
}
