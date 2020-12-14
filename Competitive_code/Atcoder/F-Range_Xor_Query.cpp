/*
Link: https://atcoder.jp/contests/abc185/tasks/abc185_f
*/

#include<bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
#define ll long long
ll e() { return 0; }
ll op(ll a,ll b) { return a^b; }
using segtree= atcoder::segtree<ll, op, e>;
int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    auto st = segtree(v);
    while (q--) {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            st.set(x - 1, st.get(x - 1) ^ y);
        } else {
            cout << st.prod(x - 1, y) << endl;
        }
    }
    return 0;
}
