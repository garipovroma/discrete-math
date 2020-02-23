#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

int n;
string s;

bool chk_zero() {
	return (s[0] == '0');
}

bool chk_one() {
	return (s[len(s) - 1] == '1');
}

bool chk_sd() {
	int m = len(s);
	for (int i = 0; i < m; i++) {
		int l = i;
		int r = m - i - 1;
		int x = s[l] - '0';
		int y = s[r] - '0';
		if ((x + y) % 2 == 0)
			return false;
	}
	return true;
}

bool chk_m() {
	int m = len(s);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			vector <int> a;
			for (int ii = 0; ii < n; ii++)
				a.push_back((i >> ii) & 1);
			vector <int> b;
			for (int ii = 0; ii < n; ii++)
				b.push_back((j >> ii) & 1);
			bool ok = true;
			for (int ii = 0; ii < n; ii++)
				if (a[ii] > b[ii])
					ok = false;
			if (ok && s[i] > s[j]) return false;
		}
	}
	return true;
}

int xxor(int a, int b){
	if (a == b) return 0;
	else return 1;
}

vector<int> get_pol(int n, string b) {
	vector <int> a(1 << n);
	for (int i = 0; i < (1 << n); i++) a[i] = b[i] - '0';
	vector <int> ans((1 << n));
	ans[0] = a[0];
	for (int i = 1; i < (1 << n); i++) {
		vector <int> q;
		for (int j = 0; j < len(a) - 1; j++) {
			q.push_back(xxor(a[j], a[j + 1]));
		}
		ans[i] = q[0];
		a = q;
	}
	return ans;
}

bool chk_lin() {
	string kek = "";
	for (int i = 0; i < (1 << n); i++)
		kek = kek + "0";
	if (kek == s) return true;
	kek = "";
	for (int i = 0; i < (1 << n); i++)
		kek = kek + "1";
	if (kek == s) return true;
	vector <int> x = get_pol(n, s);
	int sum = 0;
	int m = len(s);
	for (int i = 0; i < m; i++) sum += int(x[i]);
	int k = x[0];
	for (int i = 0; i < n; i++) {
		int ind = (1 << i);
		k += (x[ind]);
	}
	if ((k == sum)) return true;
	else return false;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	bool x1 = false;
	bool x2 = false;
	bool x3 = false;
	bool x4 = false;
	bool x5 = false;
	while(t--) {
		cin >> n >> s;
		if (!chk_zero()) x1 = true;
		if (!chk_one()) x2 = true;
		if (!chk_sd()) x3 = true;
		if (!chk_m()) x4 = true;
		if (!chk_lin()) x5 = true;
		#ifdef HOME
		cout << chk_zero()
		<< endl << chk_one()
		<< endl << chk_sd()
		<< endl << chk_m()
		<< endl << chk_lin()
		<< endl;
		#endif //HOME
		//cout << chk_sd() << endl;
		cout << endl;
	}
	if (x1 && x2 && x3 && x4 && x5) cout << "YES";
	else cout << "NO";
	return 0;
}