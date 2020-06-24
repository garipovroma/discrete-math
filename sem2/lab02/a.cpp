#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const ll MOD = 1e9 + 7;

struct automaton {
    int n = -1;
    string start;
    unordered_map <char, vector<pair<char, char>>> rules;
    vector <char> ord;
    unordered_set <char> was;
    unordered_map <char, vector<char>> sym;
    unordered_map <char, int> num;
    int start_ind = -1;
    void read_nfh() {
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
    vector <vector<pair<char, int>>> g;
    /*bool is_whitespace(char x) { return (x == ' '); }
    void process_string(string s) {
        int m = len(s);
        string a, b;
        int stage = 0;
        for (int i = 0; i < m; i++) {
            if (stage == 0) {
                if (!is_whitespace(s[i])) {
                    a.push_back(s[i]);
                } else {
                    if (i + 2 < n && s[i + 1] == '-' && s[i + 2] == '>') {
                        stage = 1;
                        i++;
                    }
                }
            } else if (stage == 1) {

            } else if (stage == 2) {

            }
        }
    }*/
    pair <string, string> read_str() {
        string a, b, c;
        cin >> a >> b >> c;
        assert(b == "->");
        return {a, c};
    }
    void process_simple_form(string a, string b) {
        int v = a[0] - 'A';
        if (len(b) == 1) {
            g[v].push_back({26, b[0]});
        } else if (len(b) == 2) {
            char c = b[0];
            int u = b[1] - 'A';
            g[v].push_back({u, c});
        }
    }
    void read_simple_form() {
        cin >> n >> start;
        g.resize(27, vector<pair<char, int>>());
        for (int i = 0; i < n; i++) {
            string cur_string;
            pair <string, string> cur_pair_of_string = read_str();
            string a = cur_pair_of_string.first;
            string b = cur_pair_of_string.second;
            process_simple_form(a, b);
        }
    }
    bool check_word(string word) {
        int m = len(word);
        int beg = start[0] - 'A';
        vector <int> q;
        vector <int> nwq;
        q.push_back(beg);
        for (int i = 0; i < m; i++) {
            char x = word[i];
            //cout << x << " : ";
            for (auto j : q) {
                for (auto v : g[j]) {
                    int u = v.first;
                    char c = v.second;
                    //cout << "{" << u << ", " << c << "} ";
                    if (c == x)	{
                        //cout << u << ' ';
                        nwq.push_back(u);
                    }
                }
            }
            //cout << endl;
            q.swap(nwq);
            nwq.clear();
        }
        for (auto i : q) {
            if (i == 26) return true;
        }
        return false;
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
    freopen("automaton.in", "rt", stdin);
	freopen("automaton.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    automaton a;
    a.read_simple_form();
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        bool query = a.check_word(s);
        if (query)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}