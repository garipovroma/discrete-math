#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const ll MOD = 1e9 + 7;

struct automaton {
	int n;
	string start;
	unordered_map <char, vector<pair<char, char>>> rules;
	vector <char> ord;
	unordered_set <char> was;
	unordered_map <char, vector<char>> sym;
	unordered_map <char, int> num;
	int start_ind = -1;
	void read() {
		for (char i = 'a'; i <= 'z'; i++)
			sym[i] = vector<char>();
		cin >> n >> start;
		for (int i = 0; i < n; i++) {
			string a, b, c;
			cin >> a >> b >> c;
			if (was.find(a[0]) == was.end()) {
				num[a[0]] = len(ord);
				ord.push_back(a[0]);
				was.insert(a[0]);
			}
			if (len(c) == 2) {
				rules[a[0]].push_back({c[0], c[1]});
			} else {
				rules[a[0]].push_back({c[0], 0});
				sym[c[0]].push_back(a[0]);
			}
		}
	}
	ll calc_word(string word) {
		int m = len(word);
		vector <vector<vector<ll>>> dp(len(was), vector<vector<ll>>(m + 1, vector<ll>(m + 1, 0)));
		for (int i = 0; i < m; i++) {
			char x = word[i];
			if (len(sym[x]) > 0)
			for (auto j : sym[x]) {
				dp[num[j]][i][i]++;
			}
		}
		for (int len = 2; len <= m; len++) {
			for (int l = 0; l + len - 1 < m; l++) {
				int r = l + len - 1;
				for (int k = l; k <= r - 1; k++) {
					for (int x = 0; x < len(ord); x++) {
						for (auto i : rules[ord[x]]) {
							if (i.second == 0) continue;
							dp[x][l][r] += dp[num[i.first]][l][k] * dp[num[i.second]][k + 1][r];
							dp[x][l][r] %= MOD;
						}
					}
				}
			}
		}
		ll res = dp[num[start[0]]][0][m - 1];
		return res;
	}
};

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("nfc.in", "rt", stdin);
	freopen("nfc.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	automaton a;
	a.read();
	int t;
	t = 1;
	string word;
	for (int i = 0; i < t; i++) {
		cin >> word;
		ll query = a.calc_word(word);
		cout << query << "\n";
	}
	return 0;
}