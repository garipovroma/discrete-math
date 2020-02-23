#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 35;

ll C[N][N];

void calc() {
	C[0][0] = 0;
	C[1][1] = 1;
	for (int i = 2; i < N; i++) {
		for (int j = 1; j < N; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
	/* for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++){
			cout << C[i][j] << ' ';
		}
		cout << endl;
	} */
}

vector <int> getChoose(int n, int k, ll num) {
	int cur = 1;
	vector <int> res;
	while (k > 0) {
		//cout << n << ' ' << k << ' ' << num << ' ' << cur << endl;
		if (C[n][k] > num) {
			res.push_back(cur);
			k--;
		} else {
			num -= C[n][k];
		}
		cur++;
		n--;
	}
	return res;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("num2choose.in", "rt", stdin);
	freopen("num2choose.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	calc();
	int n, k;
	ll m;
	cin >> n >> k >> m;
	vector <int> ans = getChoose(n, k, m);
	for (auto i : ans)
		cout << i << ' ';
	return 0;
}
