#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const int N = 2e3 + 10;
const ll M = 1e9 + 7;

bool term[N];
bool nterm[N];
ll dp[N][N];

unordered_map <char, vector<int>> g[N];
unordered_map <int, ll> ng[N];

vector <int> ord;
vector <int> used;

void tops(int v) {
	used[v] = 1;
	for (auto i : ng[v]) {
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
	freopen("problem5.in", "rt", stdin);
	freopen("problem5.out", "wt", stdout);
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
		g[a][c].push_back(b);
	}
	queue <set<int>> q;
	set <int> start_set{0};
	q.push(start_set);
	map <set<int>, int> num;
	num[start_set] = 1;
	int num_counter = 2;
	while (!q.empty()) {
		set <int> cur_set = q.front();
		/*for (auto i : cur_set) {
			cout << i << ' ';
		}
		cout << endl;*/
		q.pop();
		for (char c = 'a'; c <= 'z'; c++) {
			set <int> nw_set;
			for (auto i : cur_set) {
				for (auto j : g[i][c]) {
					nw_set.insert(j);
				}
			}
			if (nw_set.empty()) {
				continue;
			}
			if (num[nw_set] > 0) {
				ng[num[cur_set]][num[nw_set]]++;
				continue;
			} else {
				num[nw_set] = num_counter++;
				q.push(nw_set);
				ng[num[cur_set]][num[nw_set]]++;
			}
		}
	}
	for (auto kek : num) {
		for (auto x : kek.first) {
			if (term[x]) {
				nterm[kek.second] = true;
				break;
			}
		}
	}
	used.resize(num_counter + 10, 0);
	tops(1);
	reverse(all(ord));
	dp[0][1] = 1;
	for (int lenn = 0; lenn < l; lenn++) {
		for (auto i : ord) {
			for (auto j : ng[i]) {
				int x = j.first;
				dp[lenn + 1][x] += (dp[lenn][i] * 1ll * j.second) % M;
				dp[lenn + 1][x] %= M;
			}
		}
	}
	ll sum = 0;
	for (int i = 1; i < num_counter; i++) {
		if (nterm[i]) {
			sum = (sum + dp[l][i]) % M;
		}
	}
	cout << sum;
	return 0;
}