#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 60;

ll dp[N][N];

void calc() {
	dp[0][0] = 1;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j <= i; j++) {
			if (j - 1 >= 0)
				dp[i + 1][j - 1] += dp[i][j];
			if (j + 1 < N)
				dp[i + 1][j + 1] += dp[i][j];
		}
	}
}

ll get_num(string s) {
	int n = len(s);
	ll res = 0;
	int bal = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			res += dp[n - 1 - i][bal + 1];
			bal--;
		} else {
			bal++;
		}
	}
	return res;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("brackets2num.in", "rt", stdin);
	freopen("brackets2num.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	calc();
	string s;
	cin >> s;
	cout << get_num(s);
	return 0;
}
