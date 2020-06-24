#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 1e5 + 10;
const ll M = 1e9 + 7;

bool term[N];
ll dp[N];

unordered_map<int, int> g[N], gt[N];

vector <int> ord;
vector <int> used;
vector <bool> dost;

bool cycle = false;

void revdfs(int v) {
	used[v] = 1;
	for (auto i : gt[v]) {
		if (used[i.first] == 0) {
			revdfs(i.first);
		}
	}
}

void calc() {
	int n = len(used);
	for (int i = 0; i < n; i++) {
		if (term[i] && used[i] == 0) {
			revdfs(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 1) {
			dost[i] = true;
		}
	}
}

void tops(int v) {
	used[v] = 1;
	for (auto i : g[v]) {
		if (used[i.first] == 0) {
			tops(i.first);
		} else if (used[i.first] == 1 && dost[i.first]) {
			cycle = true;
		}
	}
	ord.push_back(v);
	used[v] = 2;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("problem3.in", "rt", stdin);
	freopen("problem3.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
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
		gt[b][a]++;
	}
	used.resize(n, 0);
	dost.resize(n, false);
	calc();
	used.clear();
	used.resize(n, 0);
	tops(0);
	if (cycle) {
		cout << "-1";
		return 0;
	}
	reverse(all(ord));
	dp[0] = 1;
	for (auto i : ord) {
		for (auto j : g[i]) {
			int x = j.first;
			dp[x] += ((dp[i]) % M) * j.second;
			dp[x] %= M;
		}
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (term[i]) {
			sum = (sum + dp[i]) % M;
		}
	}
	cout << sum;
	return 0;
}