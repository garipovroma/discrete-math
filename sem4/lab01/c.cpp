#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

template <typename X>
pair <vector<X>, vector<X>> get_gen_func(vector<X> a, vector<X> c) {
    int k = len(a);
    vector <X> q(k + 1, 1);
    for (int i = 1; i <= k; i++) {
        q[i] = -c[i];
    } 
    // P(t) = Q(t) * (a_0 + a_1 + ...)
    // P(t)_i = Q(t)_j * (a_(i - j))
    // p_n = a_n - \sum i = 1 .. min(n, k) c[i] * a[n - i]
    vector <X> p(k + 1);
    p[0] = a[0];
    for (int i = 1; i < k; i++) {                    
        for (int j = 1; j <= i; j++) {
            p[i] += q[j] * a[i - j];
        }                
        p[i] += a[i];                
    }        
    while (!p.empty() && p.size() != 1 && p.back() == 0) {
        p.pop_back();
    }
    while (!q.empty() && q.back() == 0) {
        q.pop_back();
    }
    return {p, q};
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#endif // HOME
    int k;
    cin >> k;
    vector <ll> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];                        
    }    
    vector <ll> c(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
       
    pair <vector<ll>, vector<ll>> res = get_gen_func(a, c);
    vector<ll> p = res.first;
    vector<ll> q = res.second;
    int x = len(p);
    int y = len(q);
    cout << x - 1 << "\n";
    for (int i = 0; i < x; i++) {
        cout << p[i] << ' ';
    }
    cout << "\n";
    cout << y - 1 << "\n";
    for (int i = 0; i < y; i++) {
        cout << q[i] << ' ';
    }
    return 0;
}  
 
