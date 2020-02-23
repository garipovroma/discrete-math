#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 20;

int dp[N][N];

void calc() {
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= N - 1; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i <= N - 1; i++)
		dp[0][i] = 1;
	dp[0][0] = 1;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= N - 1; j++) {
			if (i - j >= 0)
				dp[i][j] += dp[i - j][j - 1];
			dp[i][j] += dp[i][j - 1];
		}
	}
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= N - 1; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("num2part.in", "rt", stdin);
	freopen("num2part.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	calc();
	return 0;
}
