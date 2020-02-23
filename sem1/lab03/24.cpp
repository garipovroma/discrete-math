#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

vector <int> next_p(vector <int> &a) {
	vector <int> v;
	int n = len(a);
	for (int i = 0; i < n; i++) {
		v.push_back(a[i]);
	}
	vector <bool> was(n + 1, true);
	int id = -1;
	int mx = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (mx != -1 && mx > v[i]) {
			int j = v[i];
			for (int k = v[i] + 1; k <= n; k++) {
				if (!was[k]) {
					j = k;
					break;
				}
			}
			was[v[i]] = false;
			v[i] = j;
			was[v[i]] = true;
			id = i + 1;
			break;
		}
		was[v[i]] = false;
		mx = max(mx, v[i]);
	}
	if (id == -1) {
		for (int i = 0; i < n; i++)
			v[i] = 0;
		return v;
	}
	vector <int> unUsed;
	for (int i = 1; i <= n; i++) {
		if (!was[i])
			unUsed.push_back(i);
	}
	int pos = 0;
	for (int i = id; i < n; i++) {
		v[i] = unUsed[pos++];
	}
	return v;
}

vector <int> prev_p(vector <int> &a) {
	int n = len(a);
	vector <int> v;
	for (int i = 0; i < n; i++)
		v.push_back(a[i]);
	vector <bool> was(n + 1, true);
	int id = -1;
	int mn = 1e9;
	for (int i = n - 1; i >= 0; i--) {
		if (mn != 1e9 && mn < v[i]) {
			was[v[i]] = false;
			for (int k = v[i] - 1; k >= 1; k--) {
				if (!was[k]) {
					mn = k;
					break;
				}
			}
			v[i] = mn;
			was[mn] = true;
			id = i + 1;
			break;
		}
		was[v[i]] = false;
		mn = min(mn, v[i]);
	}
	if (id == -1) {
		for (int i = 0; i < n; i++)
			v[i] = 0;
		return v;
	}
	vector <int> unUsed;
	for (int i = 1; i <= n; i++)
		if (!was[i])
			unUsed.push_back(i);
	int pos = len(unUsed) - 1;
	for (int i = id; i < n; i++) {
		v[i] = unUsed[pos--];
	}
	return v;

}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("nextperm.in", "rt", stdin);
	freopen("nextperm.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <int> c = prev_p(a);
	vector <int> b = next_p(a);
	for (int i : c)
		cout << i << ' ';
	cout << endl;
	for (int i : b)
		cout << i << ' ';
	return 0;
}
