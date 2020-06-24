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
unordered_map <char, vector<int>> ng[N];

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
				break;
			}
			if (num[nw_set] > 0) {
				ng[num[cur_set]][c].push_back(num[nw_set]);
				continue;
			} else {
				num[nw_set] = num_counter++;
				q.push(nw_set);
				ng[num[cur_set]][c].push_back(num[nw_set]);
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
	vector <int> terms;
	for (int i = 1; i < num_counter; i++) {
		if (nterm[i]) {
			terms.push_back(i);
		}
	}
	for (auto i : num) {
		cout << i.second << ":";
		for (auto j : i.first)
			cout << j << ' ';
		cout << endl;
	}
	vector <pair<pair<int, int>, char>> edges;
	for (auto kek : num) {
		int x = kek.second;
		for (char c = 'a'; c <= 'z'; c++) {
			if (ng[x][c].size() > 0)
			for (auto y : ng[x][c]) {
				//cout << x << ' ' << y << ' ' << c << "\n";
				edges.push_back({{x, y}, c});
			}
		}
	}
	cout << num_counter << ' ' << len(edges) << ' ' << len(terms) << "\n";
	for (auto i : terms) {
		cout << i << ' ';
	}
	cout << "\n";
	for (auto i : edges) {
		cout << i.first.first << ' ' << i.first.second << ' ' << i.second << "\n";
	}
	return 0;
}