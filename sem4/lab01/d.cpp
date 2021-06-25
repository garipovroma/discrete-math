#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define len(x) int(x.size())

typedef long long ll;

const ll MOD = 998244353;

struct polynomial {
    vector <ll> coefs;
    polynomial() {
        coefs = vector<ll>();
    }
    polynomial resize(int size) {
        polynomial result = *this;
        result.coefs.resize(size);
        return result;
    }
    void shrink() {
        while(!coefs.empty() && coefs.back() == 0) {
            coefs.pop_back();
        }
    }
    polynomial(vector <ll> x) {
        coefs = vector<ll>(x);
    }
    int size() {
        return coefs.size();
    }
};

polynomial operator+(polynomial &a, polynomial &b) {
    int n = len(a);
    int m = len(b);
    int z = max(n, m) + 1;
    vector <ll> buf = vector<ll>(z);
    polynomial result = polynomial(buf);
    for (int i = 0; i < z; i++) {
        ll x = 0, y = 0;
        if (i < len(a)) {
            x += a.coefs[i];
        }
        if (i < len(b)) {
            y += b.coefs[i];
        }
        result.coefs[i] = (x + y);
    }
    result.shrink();
    return result;
}

polynomial operator-(polynomial &a) {
    polynomial result = a;
    for (int i = 0; i < len(a); i++) {
        result.coefs[i] = (MOD - result.coefs[i]) % MOD;
    }
    return result;
}

polynomial  operator-(polynomial &a, polynomial &b) {
    polynomial result = -b;
    result = result + a;
    return result;
}

polynomial operator*(polynomial &a, polynomial &b) {
    polynomial result;
    int n = len(a);
    int m = len(b);
    int z = n + m;
    vector <ll> vec(z);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vec[i + j] += a.coefs[i] * b.coefs[j];
        }
    }
    result = polynomial(vec);
    // result.shrink();
    return result;
}

polynomial division(polynomial &a, polynomial &b, int size) {
    polynomial result = polynomial(vector<ll>(size, 0));
    result.coefs[0] = a.coefs[0] / b.coefs[0];
    for (int i = 1; i < size; i++) {
        ll sum = 0;
        for (int j = max(0, i - len(b)); j < i; j++) {
            ll x = 0;
            if (i - j < len(b)) {
                x = b.coefs[i - j];
            }
            sum += ((x % MOD) * (result.coefs[j]) % MOD) % MOD;
            sum %= MOD;
        }
        ll x = ((MOD + (i < len(a) ? a.coefs[i] : 0) - sum + MOD) % MOD) / b.coefs[0];
        result.coefs[i] = x;
    }
    return result;
}

void print(polynomial &a, bool deg) {
    if (deg) {
        cout << a.size() - 1 << "\n";
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a.coefs[i] << ' ';
    }
    cout << "\n";
}

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

ll bin_pow(ll a, ll n) {
    if (n == 0) {
        return 1ll;
    }
    if (n == 1) {
        return a;
    }
    if (n % 2 == 0) {
        ll x = bin_pow(a, n / 2);
        return x * x;
    } else {
        ll x = bin_pow(a, n - 1);
        return a * x;
    }
}

int main(){
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#endif    // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll r, k;
    cin >> r >> k;
    vector <ll> v(k + 1);
    for (int i = 0; i < k + 1; i++) {
        cin >> v[i];
    }
    polynomial pol = polynomial(vector<ll>(k + 1, 0));
    for (int i = 0; i <= k; i++) {
        ll r_k = bin_pow(r, k - i);
        vector <ll> pol1 = vector<ll>(1, v[i]);
        vector <ll> pol2 = vector<ll>(1, r_k);
        polynomial x = polynomial(pol1);
        polynomial y = polynomial(pol2);
        x = x * y;
        for (int j = 0; j < k; j++) {
            vector <ll> cur = vector<ll>(2);
            cur[0] = (-i + 1 + j);
            cur[1] = 1;
            polynomial cur_pol = polynomial(cur);
            x = x * cur_pol;
        }
        pol = pol + x;
    }
    ll fact = 1;
    for (ll i = 1; i <= k; i++) {
        fact *= i;
    }
    for (int i = 0; i <= k; i++) {
        ll x = pol.coefs[i];
        ll y = bin_pow(r, k) * fact;
        ll z = gcd((x > 0 ? x : -x), y);
        // cout << z << ' ';
        x /= z;
        y /= z;
        cout << x << "/" << y << ' ';
    }
    return 0;
}
