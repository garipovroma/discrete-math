#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 20;

int p[N];
bool was[N];

ll factorial[N];

void calc() {
	factorial[0] = 1;
	for (ll i = 1; i < N; i++) {
		factorial[i] = factorial[i - 1] * i;
	}
}

ll fact(int x) {
	return factorial[x];
}

//int d = 0;

void gen(int x, int n, ll num) {
	/*d++;
	if (d == 30) return;
	cout << x << ' ' << n << ' ' << num << " : {\n";*/
	if (x == n) {
		for (int i = 0; i < n; i++) {
			cout << p[i] << ' ';
		}
	} else {
		//cout << x << " : ";
		ll cnt = num / fact(n - x - 1);
		int free = 0;
		for (int i = 1; i <= n; i++) {
			//cout << "	(" << i << ", " << num << ")\n";
			if (!was[i]) {
				free++;
				//cout << "(" << i << ", " << free << ", " << cnt <<  ") ";
				if (free == cnt + 1) {
					p[x] = i;
				//	cout << "}\n\n";
					was[i] = true;
					//cout << endl;
					gen(x + 1, n, num);
				}
				num -= fact(n - x - 1);
			}
		}
	}
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("num2perm.in", "rt", stdin);
	freopen("num2perm.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll num;
	calc();
	/*for (int i = 0; i < N; i++)
		cout << fact(i) << endl;*/
	cin >> n >> num;
	gen(0, n, num);
	return 0;
}
