/*
https://www.hackerrank.com/challenges/choose-and-calculate/problem
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define MAXN 100005
ll fact[MAXN],inv_fact[MAXN];
ll ModInv(ll x,ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        n = n / 2;
    }
    return res;
}
ll comb(ll n,ll r) {
    return (fact[n] * inv_fact[n - r] % MOD * inv_fact[r] % MOD) % MOD;
}
int main() {
    long int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "0";
        return 0;
    }
    long int a[n];
    for (long int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    fact[0] = inv_fact[0] = 1;

    for (long int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[i] = ModInv(fact[i], MOD - 2);
    }
    ll ans = 0;
    for (long int i = 0; i < n;) {
        long int e = i;
        while (e < n && a[e] == a[i]) e++;
        if (e >= k) {
            ans = (ans + (comb(e, k) - comb(i, k)) * a[i]) % MOD;
        }
        i = e;
    }
    for (long int i = n - 1; i >= 0;) {
        long int e = i;
        while (e >= 0 && a[e] == a[i]) e--;

        if (n - 1 - e >= k) {
            ans = (ans - (comb(n - 1 - e, k) - comb(n - 1 - i, k)) * a[i]) % MOD;
            //cout<<a[i]<<" "<<ans<<endl;
        }
        i = e;
    }
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;
    return 0;
}
