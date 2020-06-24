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
    bool is_whitespace(char x) { return x == ' '; }
    int _pos = 0;
    vector<vector<string>> gg;
    void skip_whitespaces(string &s) {
        int m = len(s);
        while(_pos < m && is_whitespace(s[_pos])) {
            _pos++;
        }
    }
    string get_token(string &s) {
        skip_whitespaces(s);
        string res = "";
        int m = len(s);
        while (_pos < m && !is_whitespace(s[_pos])) {
            res.push_back(s[_pos++]);
        }
        return res;
    }
    void process_extended_form(string s) {
        string a, b, c;
        a = get_token(s);
        b = get_token(s);
        c = get_token(s);
        //cout << a << ' ' << b << ' ' << c << endl;
        _pos = 0;
        assert(_pos == 0);
        assert(b == "->");
        gg[a[0] - 'A'].push_back(c);
    }
    void read_extended_form() {
        gg.resize(26, vector<string>());
        int n;
        cin >> n;
        getline(cin, start);
        for (int i = 0; i < n; i++) {
            string cur_string;
            getline(cin, cur_string);
            process_extended_form(cur_string);
        }
    }
    vector<char> find_eps() {
        unordered_set <char> eps_set;
        for (char i = 'A'; i <= 'Z'; i++) {
            for (auto j : gg[i - 'A']) {
                if (j.empty()) {
                    eps_set.insert(i);
                    break;
                }
            }
        }
        unordered_set <char> nw_set;
        while (true) {
            bool stop_ = true;
            for (char i = 'A'; i <= 'Z'; i++) {
                for (auto j : gg[i - 'A']) {
                    bool ok = true;
                    for (auto k : j) {
                        if ('a' <= k && k <= 'z') {
                            ok = false;
                            break;
                        }
                        if (eps_set.find(k) == eps_set.end()) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok && eps_set.find(i) == eps_set.end()) {
                        nw_set.insert(i);
                        stop_ = false;
                    }
                }
            }
            if (!nw_set.empty()) {
                for (auto i : nw_set) {
                    eps_set.insert(i);
                }
            }
            if (stop_) {
                break;
            }
            nw_set.clear();
        }
        vector <char> res;
        for (char i = 'A'; i <= 'Z'; i++) {
            if (eps_set.find(i) != eps_set.end()) {
                res.push_back(i);
            }
        }
        return res;
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
                    if (c == x) {
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
    freopen("epsilon.in", "rt", stdin);
    freopen("epsilon.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    automaton a;
    a.read_extended_form();
    vector <char> ans = a.find_eps();
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}