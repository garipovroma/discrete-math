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
			if (j + 1 < N)
				dp[i + 1][j + 1] += dp[i][j];
			if (j - 1 >= 0)
				dp[i + 1][j - 1] += dp[i][j];
		}
	}
}

void getPSP(int n, ll num) {
	string s = "";
	int bal = 0;
	for (int i = 0; i < 2 * n; i++) {
		ll cur = dp[2 * n - (i + 1)][bal + 1];
		if (cur <= num) {
			s += ")";
			bal--;
			num -= cur;
		} else {
			s += "(";
			bal++;
		}
	}
	cout << s;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("num2brackets.in", "rt", stdin);
	freopen("num2brackets.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	calc();
	int n;
	ll num;
	cin >> n >> num;
	getPSP(n, num);
	return 0;
}
