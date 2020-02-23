#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 35;

ll C[N][N];

void calc() {
	C[0][0] = 1;
	C[1][1] = 1;
	C[1][0] = 1;
	for (int i = 2; i < N; i++) {
		for (int j = 1; j < N; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
		C[i][0] = 1;
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cout << C[i][j] << ' ';
		}
		cout << endl;
	}*/
}

ll getNum(vector <int> &a, int n) {
	ll res = 0;
	int k = len(a);
	for (int i = 0; i < k; i++) {
		int l;
		if (i == 0) {
			l = 0;
		} else {
			l = a[i - 1];
		}
		l++;
		int r = a[i] - 1;
		for (int j = l; j <= r; j++) {
			res += C[n - j][k - i - 1];
			// cout << i << ' ' << j << endl;
		}
	}
	return res;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("choose2num.in", "rt", stdin);
	freopen("choose2num.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	calc();
	int n, k;
	cin >> n >> k;
	vector <int> a(k);
	for (int i = 0; i < k; i++)
		cin >> a[i];
	cout << getNum(a, n);
	return 0;
}
