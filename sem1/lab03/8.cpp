#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 100;

int p[N];
bool used[N];

void gen(int x, int n, int k, int prev) {
	if (x == k) {
		for (int i = 0; i < k; i++)
			cout << p[i] + 1 << ' ' ;
		cout << "\n";
	} else {
		for (int i = prev; i < n; i++) {
			if (!used[i]) {
				used[i] = true;
				p[x] = i;
				gen(x + 1, n, k, i + 1);
				used[i] = false;
			}
		}
	}
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("choose.in", "rt", stdin);
	freopen("choose.out", "wt", stdout);
	#endif  //  HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	gen(0, n, k, 0);
	return 0;
}
