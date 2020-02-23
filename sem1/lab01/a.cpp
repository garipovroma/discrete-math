#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#endif //  HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector <pair<int, int>> a;
	vector <pair<int, int>> b;
	set< pair<int, int>> was;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		if (was.find({x, y}) != was.end()) continue;
		a.push_back({x, y});
		was.insert({x, y});
		b.push_back({x, y});
		b[(int)b.size() - 1].first = abs(x) - 1;
		b[(int)b.size() - 1].second = abs(y) - 1;
	}
	//cout << endl;
	for (int i = 0; i < (1 << n); i++) {
		int z = 1;
		/*for (int x = 0; x < n; x++)
			cout << ((i >> x) & 1);
		cout << " : ";*/
		for (int j = 0; j < b.size(); j++) {
			int x = (i >> ((b[j].first))) & 1;
			int y = (i >> ((b[j].second))) & 1;
			if (a[j].first < 0) x = 1 - x;
			if (a[j].second < 0) y = 1 - y;
			//cout << "(" << x << " + " << y << ")" << " * ";
			if (x + y == 0) {
				z = 0;
				break;
			}
		}
		//cout << endl;
		if (z == 1) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}