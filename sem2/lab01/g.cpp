#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 1e3 + 10;
const ll M = 1e9 + 7;

bool used[N][N];

struct kek{
	bool term[N];
	unordered_map <char, int> g[N];
	unordered_map <char, int> tg[N];
	bool att[N];
	int n, m, k;
	kek(int n_, int m_, int k_) {
		n = n_;
		m = m_;
		k = k_;
		for (int i = 0; i < n_; i++) {
			for (char c = 'a'; c <= 'z'; c++)
					g[i][c] = N - 1;
		}
	}

	void read() {
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
			g[a][c] = b;
			tg[b][c] = a;
		}
	}
	void rev_dfs(int v, vector <bool> &used) {
		used[v] = true;
		for (auto i : tg[v]) {
			if (!used[i.second]) {
				rev_dfs(i.second, used);
			}
		}
	}

	void calc_attainability() {
		vector <bool> used(n, false);
		for (int i = 0; i < n; i++) {
			if (term[i] && !used[i]) {
				rev_dfs(i, used);
			}
		}
		for (int i = 0; i < n; i++) {
			att[i] = used[i];
		}
	}
};


int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("equivalence.in", "rt", stdin);
	freopen("equivalence.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	kek v1 = kek(n, m, k);
	v1.read();
	cin >> n >> m >> k;
	kek v2 = kek(n, m, k);
	v2.read();
	v1.calc_attainability();
	v2.calc_attainability();
	queue <pair<int, int>> q;
	used[0][0] = true;
	q.push({0, 0});
	bool ans = true;
	while (!q.empty()) {
		pair <int, int> cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		if (v1.term[x] != v2.term[y]) {
			ans = false;
		}
		//cout << x << ' ' << y  << " : " << endl;
		for (char c = 'a'; c <= 'z'; c++) {
			int nx = v1.g[x][c];
			int ny = v2.g[y][c];
			//cout << c << ' ' << nx << ' ' << ny << endl;
			if (nx == N - 1 && ny != N - 1 && v2.att[ny]) {
				ans = false;
				break;
			}
			if (ny == N - 1 && nx != N - 1 && v1.att[nx]) {
				ans = false;
				break;
			}
			if (nx != N - 1 && ny != N - 1 && !used[nx][ny]) {
				q.push({nx, ny});
				used[nx][ny] = true;
			}
		}
	}
	if (ans) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}