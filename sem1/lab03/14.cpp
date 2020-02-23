#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 20;

ll p[N];

void calc() {
	p[0] = 1;
	for (int i = 1; i < N; i++) {
		p[i] = p[i - 1] * i;
	}
}

ll fact(int x) {
	return p[x];
}

ll get_permutation_index(vector <int> &a) {
	int n = len(a);
	vector <bool> was(n + 1, false);
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 1; j <= a[i] - 1; j++) {
			if (!was[j]) {
				k++;
				res += fact(n - i - 1);
				cout << j << ' ';
			}
		}
		cout << endl;
		cout << k << " * " << n - i - 1 << "!     ######################" << endl << endl << endl;
		was[a[i]] = true;
	}
	return res;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("perm2num.in", "rt", stdin);
	freopen("perm2num.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	calc();
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << get_permutation_index(a);
	return 0;
}
