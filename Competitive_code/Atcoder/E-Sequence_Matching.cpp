/*
Link: https://atcoder.jp/contests/abc185/tasks/abc185_e
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;
ll a[N],b[N],dp[N][N],n,m;
ll Solve(ll i,ll j) {
    if (i == 0 && j == 0)
        return 0;
    else if (i == 0)
        return j;
    else if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll res = LLONG_MAX;
    if (a[i] == b[j]) {
        res = min(res, Solve(i - 1, j - 1));
        res = min(res, Solve(i - 1, j) + 1);
        res = min(res, Solve(i, j - 1) + 1);
    } else {
        res = min(res, Solve(i - 1, j - 1) + 1);
        res = min(res, Solve(i - 1, j) + 1);
        res = min(res, Solve(i, j - 1) + 1);
    }
    return (dp[i][j] = res);
}
int main() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= m; i++)
        cin >> b[i];
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= m; j++)
            dp[i][j] = -1;
    }
    ll Ans = Solve(n, m);
    cout << Ans << endl;
    return 0;
}
