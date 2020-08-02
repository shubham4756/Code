/*
Link:https://atcoder.jp/contests/abc174/tasks/abc174_f
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
const int B=700;

bool mycomp(pair<  pair<ll,ll> ,ll > a,pair<  pair<ll,ll> ,ll > b) {
    return a.first.first/B < b.first.first/B || (a.first.first/B == b.first.first/B && a.first.second < b.first.second);
}
const int N=500005;
int mp[N]={0};

void solve() {
    ll n, q;
    cin >> n >> q;
    ll a[n];
    for (long int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<pair<ll, ll>, ll> > v;
    for (long int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        v.pb({{l, r}, i});
    }
    sort(v.begin(), v.end(), mycomp);
    ll L = v[0].first.first;
    ll R = v[0].first.second, cnt = 0;
    ll ans[q];
    for (ll i = L; i <= R; i++) {
        mp[a[i]]++;
        if (mp[a[i]] == 1)
            cnt++;
    }
    ans[v[0].second] = cnt;
    for (ll i = 1; i < q; i++) {
        ll pL = v[i].first.first;
        ll pR = v[i].first.second;
        while (L < pL) {
            mp[a[L]]--;
            if (mp[a[L]] == 0) cnt--;
            L++;
        }
        while (pL < L) {
            L--;
            mp[a[L]]++;
            if (mp[a[L]] == 1) cnt++;
        }
        while (R > pR) {
            mp[a[R]]--;
            if (mp[a[R]] == 0) cnt--;
            R--;
        }
        while (R < pR) {
            R++;
            mp[a[R]]++;
            if (mp[a[R]] == 1) cnt++;
        }
        ans[v[i].second] = cnt;
    }
    for (ll i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
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
