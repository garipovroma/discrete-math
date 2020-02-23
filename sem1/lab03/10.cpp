#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

const int N = 100;

int p[N];
bool used[N];

int n, ans = 0;

void gen(int x, int sum) {
	if (sum == 0) {
		unordered_map <int, int> cnt;
		for (int i = 0; i < x; i++) {
			cnt[p[i]]++;
		}
		for (auto i : cnt) {
			if (i.second > 1)
				return;
		}
		for (int i = 0; i < x; i++) {
			cout << p[i];
			if (i != x - 1)
				cout << "+";
		}
		cout << "\n";
		ans++;
	}
	else {
		int beg;
		if (x == 0)
			beg = 1;
		else
			beg = p[x - 1];
		for (int c = beg; c <= sum; c++) {
			p[x] = c;
			gen(x + 1, sum - c);
		}
	}
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("partition.in", "rt", stdin);
	freopen("partition.out", "wt", stdout);
	#endif  //  HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	gen(0, n);
	cout << ans << endl;
	return 0;
}
