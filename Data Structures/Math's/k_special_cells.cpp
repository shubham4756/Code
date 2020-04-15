/*
Link:https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/shinos-k-special-cells-c8538ebb/description/
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//const long MAXN=100;
typedef long long int ll;
ll ModInv(ll x,ll n){
    ll res=1;
    while(n){
        if(n&1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return res;
}
int main() {
    ll fact[1000001];
    fact[0] = fact[1] = 1;
    for (ll i = 2; i < 1000001; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    long t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        ll ans = 0;
        while (k--) {
            ll x, y, p;
            cin >> x >> y >> p;
            x--;
            y--;
            ll sum = fact[x + y] % mod;
            sum = (sum * ModInv(fact[x], mod - 2)) % mod;
            sum = (sum * ModInv(fact[y], mod - 2)) % mod;
            x = n - x - 1;
            y = m - y - 1;
            sum = (sum * fact[x + y]) % mod;
            sum = (sum * ModInv(fact[x], mod - 2)) % mod;
            sum = (sum * ModInv(fact[y], mod - 2)) % mod;
            sum = (sum * p) % mod;
            ans = (ans + sum) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
