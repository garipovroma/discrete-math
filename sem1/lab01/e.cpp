#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

struct kek{
	int m;
	vector <int> in, val;
	kek(){}
	kek(int mm, vector <int> inn, vector <int> vval) {
		m = mm;
		in = inn;
		val = vval;
	}
};

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#endif //HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector <kek> v;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		vector <int> a(m);
		for (int j = 0; j < m; j++) {
			cin >> a[j];
			a[j]--;
		}
		reverse(all(a));
		vector <int> val(1 << m);
		if (m > 0)
			for (int j = 0; j < (1 << m); j++)
				cin >> val[j];
		v.push_back(kek(m, a, val));
	}
	vector <int> depth(n, 0);
	for (int i = 0; i < n; i++) {
		if (v[i].m != 0) {
			for (int j : v[i].in)
				depth[i] = max(depth[i], depth[j] + 1);
		}
	}
	int mx = -1;
	for (int i = 0; i < n; i++) {
		mx = max(mx, depth[i]);
	}
	vector <int> ord;
	for (int i = 0; i < n; i++) {
		if (v[i].m == 0) {
			ord.push_back(i);
		}
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (v[i].m > 0)
			root = i;
	}
	int N = len(ord);
	reverse(all(ord));
	vector <int> ans;
	cout << mx << endl;
	for (int msk = 0; msk < (1 << N); msk++) {
		vector <int> d(n, 1e9);
		for (int j = N - 1; j >= 0; j--) {
			d[ord[j]] = (msk >> j) & 1;
		}
		for (int i = 0; i < n; i++) {
			if (v[i].m == 0) continue;
			int get = 0;
			for (int j = 0; j < v[i].m; j++) {
				int in = v[i].in[j];
				int z = d[in];
				get ^= (z << (j));
			}
			int val = v[i].val[get];
			d[i] = val;
		}
		cout << d[n - 1];
	}
	return 0;
}