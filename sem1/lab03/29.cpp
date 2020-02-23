#include <bits/stdc++.h>

using namespace std;

#define len(x) int(x.size())
#define all(x) x.begin(), x.end()

typedef long long ll;

int get1(vector <int> &kek) {
    return kek[len(kek) - 2];
}

int get0(vector <int> &kek) {
    return kek[len(kek) - 1];
}

int get2(vector <int> &kek) {
    return kek[len(kek) - 3];
}

int pos0(vector <int> &kek) {
    return (len(kek) - 1);
}

int pos1(vector <int> &kek) {
    return (pos0(kek) - 1);
}

int pos2(vector <int> &kek) {
    return (pos1(kek) - 1);
}

void kill_zeros(vector <int> &a) {
    while (len(a) > 0 && get0(a) == 0) {
        a.pop_back();
    }
}

void modify(vector <int> &a) {
    while (a[pos0(a)] >= 2 * a[pos1(a)]) {
    	int x = a[pos1(a)];
    	int y = a[pos0(a)] - a[pos1(a)];
        a[pos0(a)] = x;
        a.push_back(y);
    }
}

vector <int> get_next(vector <int> a) {
    vector <int> v;
    for (int i : a)
        v.push_back(i);
    v[pos0(v)]--;
    v[pos1(v)]++;
    if (get1(v) > get0(v)) {
        v[pos1(v)] = v[pos1(v)] + v[pos0(v)];
        v[pos0(v)] = 0;
        v.pop_back();
    } else {
        modify(v);
    }
    kill_zeros(v);
    return v;
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("nextpartition.in", "rt", stdin);
	freopen("nextpartition.out", "wt", stdout);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    char cinableChar;
    int sum = 0;
    vector <int> a;
    while(sum < x) {
        cin >> cinableChar;
        int cur;
        cin >> cur;
        a.push_back(cur);
        sum += cur;
    }
    if (len(a) == 1) {
        cout << "No solution";
        return 0;
    }
    vector <int> ans = get_next(a);
    cout << x << "=";
    int id = 0;
    for (int i : ans) {
        cout << i;
        if (id != len(ans) - 1)
        	cout << "+";
        id++;
    }
    return 0;
}
