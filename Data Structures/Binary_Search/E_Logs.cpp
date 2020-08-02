/*
Link:https://atcoder.jp/contests/abc174/tasks/abc174_e
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << endl;
#define endl "\n"
#define MOD (int) 1e9+7
#define inf (int) (1e18)

ll findCut(ll a[],ll n,ll mid){
    ll res=0;
    for(long int i=0;i<n;i++)
        res+=(a[i]-1)/mid;
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (long int i = 0; i < n; i++)
        cin >> a[i];

    ll l = 1, r = INT_MAX, ans = INT_MAX;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll x = findCut(a, n, mid);
        if (x <= k) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    // cin >> t;
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}
