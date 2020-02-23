#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 11;

int a[N];
vector <vector<int>> p;

void gen(int x, int n) {
	if (x == n - 1) {
		p.push_back(vector<int>(0));
		p[len(p) - 1].push_back(0);
		for (int i = 0; i < n - 1; i++)
			p[len(p) - 1].push_back(a[i]);
	} else {
		for (int i = 1; i <= 3; i++) {
			a[x] = i - 1;
			gen(x + 1, n);
		}
	}
}

vector <int> shift(vector <int> &a, int x) {
	vector <int> res(len(a));
	int n = len(a);
	for (int i = 0; i < n; i++) {
		res[(i + x) % n] = a[i];
	}
	return res;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("antigray.in", "rt", stdin);
	freopen("antigray.out", "wt", stdout);
	#endif  //   HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	gen(0, n);
	for (auto i : p) {
		for (int j : i)
			cout << j;
		cout << "\n";
		for (int j : i) {
			cout << (j + 1) % 3;
		}
		cout << "\n";
		for (int j : i) {
			cout << (j + 2) % 3;
		}
		cout << "\n";
	}
	return 0;
}

