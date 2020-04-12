/*
Link:https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/merge-the-boxes-7fb988ac/
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;
ll sz[1000005];
ll pre[1000005];
ll a[1000005];
pair<ll ,ll> min_max[1000005];
ll root(ll x) {
    while (pre[x] != x) {
        x = pre[x];
    }
    return x;
}
void makeunion(ll x,ll y) {
    ll xpre = root(x);
    ll ypre = root(y);
    if (xpre == ypre) {
        // printf("%lld %lld\n",min_max[xpre].first,min_max[xpre].second);
        return;
    }
    if (sz[xpre] >= sz[ypre]) {
        sz[xpre] += sz[ypre];
        pre[ypre] = xpre;
        min_max[xpre].first = min({min_max[xpre].first, min_max[ypre].first});
        min_max[xpre].second = max({min_max[xpre].second, min_max[ypre].second});
        //printf("%lld %lld\n",min_max[xpre].first,min_max[xpre].second);
    } else {
        sz[ypre] += sz[xpre];
        pre[xpre] = ypre;
        min_max[ypre].first = min({min_max[ypre].first, min_max[xpre].first});
        min_max[ypre].second = max({min_max[ypre].second, min_max[xpre].second});
        //printf("%lld %lld\n",min_max[ypre].first,min_max[ypre].second);
    }
}
void solve() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sz[i] = 1;
        pre[i] = i;
        min_max[i] = {a[i], a[i]};
    }
    ll q;
    scanf("%lld", &q);
    while (q--) {
        ll ty;
        scanf("%lld", &ty);
        if (ty == 1) {
            ll x, y;
            scanf("%lld", &x);
            scanf("%lld", &y);
            makeunion(x, y);
        } else {
            ll x;
            scanf("%lld", &x);
            long xpre = root(x);
            cout << min_max[xpre].second - min_max[xpre].first << endl;
        }
    }
}
int main() {
//    long t;
//    cin>>t;
//    while(t--)
    solve();
    return 0;
}
