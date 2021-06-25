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
    polynomial(polynomial const &x) {
        coefs = vector<ll>(x.coefs);
    }
    ll &operator[](int id) {
        return coefs[id];
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
            x += a[i];
        }
        if (i < len(b)) {
            y += b[i];
        }
        result[i] = (x + y + MOD) % MOD;
    }
    result.shrink();
    return result;
}

polynomial operator-(polynomial &a) {
    polynomial result = a;
    for (int i = 0; i < len(a); i++) {
        result[i] = (MOD - result[i]) % MOD;
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
            vec[i + j] += (a[i] * b[j]) % MOD;
            vec[i + j] %= MOD;
        }
    }
    result = polynomial(vec);
    result.shrink();
    return result;
}

polynomial division(polynomial &a, polynomial &b, int size) {
    polynomial result = polynomial(vector<ll>(size, 0));
    result[0] = a[0] / b[0];
    for (int i = 1; i < size; i++) {
        ll sum = 0;
        for (int j = max(0, i - len(b)); j < i; j++) {
            ll x = 0;
            if (i - j < len(b)) {
                x = b[i - j];
            }
            sum += ((x % MOD) * (result[j]) % MOD) % MOD;
            sum %= MOD;
        }
        ll x = ((MOD + (i < len(a) ? a[i] : 0) - sum + MOD) % MOD) / b[0];
        result[i] = x;
    }
    return result;
}

void print(polynomial &a, bool deg) {
    if (deg) {
        cout << a.size() - 1 << "\n";
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
    cout << "\n";
}

int main(){
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#endif    // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <ll> x(n + 1), y(m + 1);
    for (int i = 0; i < n + 1; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m + 1; i++) {
        cin >> y[i];
    }
    polynomial a = polynomial(x);
    polynomial b = polynomial(y);
    polynomial c = a + b;
    polynomial e = a * b;
    polynomial f = division(a, b, 1000);
    print(c, true);
    print(e, true);
    print(f, false);
    return 0;
}
