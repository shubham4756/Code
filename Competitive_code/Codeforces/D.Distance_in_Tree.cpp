/*
Link: https://codeforces.com/problemset/problem/161/D
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";

template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int  MOD=1000000007;
const int N=50005;
ll n,k,Ans=0;
vector<ll> g[N];
ll dp[N][505];

void dfs(ll nd,ll pt) {
    dp[nd][0] = 1;
    for (auto it:g[nd]) {
        if (it != pt) {
            dfs(it, nd);

            for (ll i = 1; i <= k; i++)
                Ans += dp[nd][k - i] * dp[it][i - 1];

            for (ll i = 1; i <= k; i++)
                dp[nd][i] += dp[it][i - 1];
        }
    }
}

void solve() {
    cin >> n >> k;
    for (ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, -1);
    cout << Ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;                     // DON'T FORGET IT. ^^^
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
