/*
Link: https://codeforces.com/problemset/problem/682/C
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 100005;
const int Mod = 1000000007;
vector<pair<ll, ll> > g[N];
vector<ll> v(N);
ll n;

ll Dfs(ll nd, ll pt, ll sum, ll minSum) {
    if (sum - minSum > v[nd])
        return 0;
    ll r = 1;
    for (pair<ll, ll> p : g[nd]) {
        ll tp = sum + p.second;
        r += Dfs(p.first, nd, tp, min(minSum, tp));
    }
    return r;
}

int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    for (ll i = 1; i < n; i++) {
        ll p1, c1;
        cin >> p1 >> c1;
        g[p1].push_back({i + 1, c1});
    }
    ll res = n - Dfs(1, 0, 0, 0);
    cout << res;
    return 0;
}
