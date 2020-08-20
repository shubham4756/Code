/*
Link:https://www.codechef.com/CENS2020/problems/CENS20E
Editorial: https://discuss.codechef.com/t/cens20e-editorial/75412
*/

/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
const int  MOD=1000000007;
const int N=200011;

vector<int> g[N];
bool vis[N];
ll val[N];
ll ans;

void dfs(int nd,int check) {
    vis[nd] = true;
    for (int i = 0; i < g[nd].size(); i++) {
        if (!vis[g[nd][i]] && __builtin_parity(val[g[nd][i]]) == check) {
            ans++;
            dfs(g[nd][i], check);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        vis[i] = false, g[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ll eveP = 0, oddP = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (__builtin_parity(val[i])) {
                ans = 1;
                dfs(i, 1);
                oddP = max(oddP, ans);
            } else {
                ans = 1;
                dfs(i, 0);
                eveP = max(eveP, ans);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int ty, k;
        cin >> ty >> k;
        if (ty == 1) {
            if (__builtin_parity(k))
                cout << eveP << endl;
            else
                cout << oddP << endl;
        } else {
            if (__builtin_parity(k))
                cout << oddP << endl;
            else
                cout << eveP << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    cin >> t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
