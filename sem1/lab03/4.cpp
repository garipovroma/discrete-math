#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

namespace std {
template<>
class hash<vector<int>> {
public:
    size_t operator()(const vector<int> &s) const
    {
        size_t h = 0;
        for (int i = 0; i < len(s); i++) {
        	h = h * 31 + s[i];
        }
        return h;
    }
};
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("chaincode.in", "rt", stdin);
	freopen("chaincode.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	unordered_set<vector<int>> s;
	vector <vector<int>> ord;
	vector <int> cur(n, 0);
	s.insert(cur);
	ord.push_back(cur);
	while (true) {
		vector <int> nw;
		for (int i = 1; i < n; i++)
			nw.push_back(cur[i]);
		nw.push_back(1);
		vector <int> pajiloy = nw;
		pajiloy[len(pajiloy) - 1] = 0;
		if (s.find(nw) == s.end()) {
			cur.swap(nw);
		} else if (s.find(pajiloy) == s.end()) {
			pajiloy.swap(cur);
		} else {
			break;
		}
		s.insert(cur);
		ord.push_back(cur);
	}
	for (auto i : ord) {
		for (int j : i)
			cout << j;
		cout << "\n";
	}
	return 0;
}
