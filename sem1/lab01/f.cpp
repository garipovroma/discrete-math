#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())

int xxor(int a, int b){
	if (a == b) return 0;
	else return 1;
}

int main() {
	#ifdef HOME
	freopen("input.txt", "rt", stdin);
	#endif //HOME
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	vector <int> a;
	vector <string> v;
	for (int i = 0; i < (1 << n); i++) {
		int x;
		cin >> s >> x;
		//cout << s << endl;
		v.push_back(s);
		a.push_back(x);
	}
	vector <int> ans((1 << n));
	ans[0] = a[0];
	cout << v[0] << ' ' << ans[0] << "\n";
	for (int i = 1; i < (1 << n); i++) {
		vector <int> q;
		for (int j = 0; j < len(a) - 1; j++) {
			q.push_back(xxor(a[j], a[j + 1]));
		}
		ans[i] = q[0];
		/*for (auto j : q)
			cout << j << ' ';
		cout << endl;*/
		cout << v[i] << ' ' << ans[i] << "\n";
		a = q;
	}
	return 0;
}