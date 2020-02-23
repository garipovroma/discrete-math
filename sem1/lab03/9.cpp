#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 100;

int p[N];
bool used[N];

void gen(int x, int n, int bal) {
	if (x == n * 2) {
		for (int i = 0; i < 2 * n; i++)
			if (p[i] == 0)
				cout << "(";
			else
				cout << ")";
		cout << "\n";
	} else {
		if (bal + 1 <= 2 * n - x - 1) {
			p[x] = 0;
			gen(x + 1, n, bal + 1);
		}
		if (bal - 1 >= 0) {
			p[x] = 1;
			gen(x + 1, n, bal - 1);
		}

	}
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("brackets.in", "rt", stdin);
	freopen("brackets.out", "wt", stdout);
	#endif  //  HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	gen(0, n, 0);
	return 0;
}
