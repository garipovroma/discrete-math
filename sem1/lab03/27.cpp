#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

string next_bracket_sequence(string s) {
	int n = len(s);
	string v = "";
	for (int i = 0; i < n; i++)
		v.push_back(s[i]);
	int bal = 0;
	vector <int> b(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			bal++;
		else
			bal--;
		b[i] = bal;
	//	cout << b[i] << ' ';
	}
	//cout << endl;
	int id = -1;
	for (int i = n - 1; i >= 0; i--) {
		//cout << b[i] - 2 << ' ' << n - i + 1 << endl;
		if (s[i] == '(' && b[i] - 2 >= 0 && n - i + 1 >= b[i] - 2) {
			id = i + 1;
			v[i] = ')';
			bal = b[i] - 2;
			break;
		}
	}
	/*
	cout << endl;
	cout << id << ' ' << bal << endl;*/
	if (id == -1) {
		return "-";
	}
	char x = '(';
	for (int j = id; j < n; j++) {
		int lost = n - 1 - j + 1;
		if (lost == bal) {
			x = ')';
			bal = 1e9;
		}
		bal++;
		v[j] = x;
	}
	return v;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#else
	freopen("nextbrackets.in", "rt", stdin);
	freopen("nextbrackets.out", "wt", stdout);
	#endif // HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	cout << next_bracket_sequence(s);
	return 0;
}
