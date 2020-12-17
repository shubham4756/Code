/*
Link: https://codeforces.com/problemset/problem/1401/D
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
const int Mod=1000000007;
vector<ll> v;
ll n,m,A[N],sz[N];
void DFS(ll nd,ll pt,vector<ll> g[]) {
    sz[nd] = 1;
    for (auto it: g[nd]) {
        if (it != pt) {
            DFS(it, nd, g);
            sz[nd] += sz[it];
        }
    }
    if (pt != 0)
        v.push_back(sz[nd] * (n - sz[nd]));
}
void solve() {
    v.clear();
    cin >> n;
    vector<ll> g[n + 2];
    for (ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> m;
    for (ll i = 1; i <= m; i++)
        cin >> A[i];
    sort(A + 1, A + m + 1);
    DFS(1, 0, g);
    sort(v.begin(), v.end());
    while (m > n - 1) {
        A[m - 1] = (A[m] * A[m - 1]) % Mod;
        m--;
    }
    ll Ans = 0;
    for (ll i = n - 2; i >= 0; i--) {
        if (m == 0) {
            Ans = (Ans + v[i]) % Mod;
        } else {
            Ans = (Ans + v[i] * A[m]) % Mod;
            m--;
        }
    }
    cout << Ans << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
