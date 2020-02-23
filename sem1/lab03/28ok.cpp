#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (next_permutation(a.begin(), a.end()))
	for (int i : a)
		cout << i << ' ';
	else
		cout << -1 << ' ';
	return 0;
}
