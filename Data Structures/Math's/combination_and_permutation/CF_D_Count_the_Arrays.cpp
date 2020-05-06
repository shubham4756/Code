/*
Link:https://codeforces.com/problemset/problem/1312/D
Editorial is best for explnation
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 998244353
const ll MAXN=200010;
ll fact[MAXN];
void pre() {
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}
ll power(ll x,ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        n = n / 2;
    }
    return res % MOD;
}
ll ncr(ll n,ll r) {
    return (fact[n] * power((fact[r] * fact[n - r]) % MOD, MOD - 2) % MOD) % MOD;
}
int main() {
    pre();
    ll n, m;
    cin >> n >> m;
    n = n % MOD;
    m = m % MOD;
    ll ans = 0;
    if (n > 2) {
        ans = ncr(m, n - 1) % MOD;
        ans = (ans * (n - 2)) % MOD;
        ans = (ans * power(2, n - 3)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
