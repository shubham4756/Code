/*
Link:https://codeforces.com/problemset/problem/1301/C
editorial is best for understood
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 998244353
int main() {
    long int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll z = n - m;
        ll g = m + 1;
        ll k = z / g;
        ll ans = (n * (n + 1)) / 2LL;
        ans -= g * (k * (k + 1)) / 2LL;
        ans -= (z % g) * (k + 1);
        cout << ans << endl;
    }
    return 0;
}
