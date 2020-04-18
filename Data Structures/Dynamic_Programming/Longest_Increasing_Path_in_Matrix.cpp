/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/longest-increasing-path-9/
Learning:https://www.geeksforgeeks.org/longest-increasing-path-matrix/
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[105][105],a[105][105];
ll LIP(ll n,ll m,ll x,ll y){
    if (dp[x][y] < 0) {
        ll res = 1;
        if (x == n - 1 && y == m - 1)
            return dp[x][y]=1;
       if (a[x][y] < a[x + 1][y])
            res = 1 + LIP(n, m, x + 1, y);
        if (a[x][y] < a[x][y + 1])
            res = max(res, 1 + LIP(n, m, x, y + 1));
        dp[x][y] = res;
    }
   // cout<<x<<" "<<y<<" "<<dp[x][y]<<endl;
    return dp[x][y];
}
void solve() {
    ll n, m;
    cin >> n >> m;
    memset(a,-1, sizeof(a));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            cin >> a[i][j];
    }
    memset(dp,-1, sizeof(dp));
    cout << max(1LL,LIP(n, m, 0, 0))<< endl;
}
int main() {
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
