#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 100;

int p[N];
bool used[N];

void gen(int x, int n) {
	if (x == n) {
		for (int i = 0; i < n; i++)
			cout << p[i] + 1 << ' ' ;
		cout << "\n";
	} else {
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				used[i] = true;
				p[x] = i;
				gen(x + 1, n);
				used[i] = false;
			}
		}
	}
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("permutations.in", "rt", stdin);
	freopen("permutations.out", "wt", stdout);
	#endif  //  HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	gen(0, n);
	return 0;
}
