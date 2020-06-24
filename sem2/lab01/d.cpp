#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 1e3 + 10;
const ll M = 1e9 + 7;

bool term[N];
ll dp[N][N];

unordered_map<int, int> g[N];

vector <int> ord;
vector <int> used;

void tops(int v) {
	used[v] = 1;
	for (auto i : g[v]) {
		if (used[i.first] == 0) {
			tops(i.first);
		}
	}
	ord.push_back(v);
	used[v] = 2;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("problem4.in", "rt", stdin);
	freopen("problem4.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		x--;
		term[x] = true;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a][b]++;
	}
	used.resize(n, 0);
	tops(0);
	reverse(all(ord));
	dp[0][0] = 1;
	for (int lenn = 0; lenn < l; lenn++) {
		for (auto i : ord) {
			for (auto j : g[i]) {
				int x = j.first;
				dp[lenn + 1][x] += (dp[lenn][i] * 1ll * j.second) % M;
				dp[lenn + 1][x] %= M;
			}
		}
	}/*
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j < n; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}*/
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (term[i]) {
			sum = (sum + dp[l][i]) % M;
		}
	}
	cout << sum;
	return 0;
}