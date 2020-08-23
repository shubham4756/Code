/*
Link:https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-22-august-2020/challenges/long-live-the-king-2
Editorial:https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-22-august-2020/challenges/long-live-the-king-2/editorial
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

const int  mod=1000000007;
const ll inf=10000000000000000;
const int N=100010;
ll n,m;
vector<pair<ll,ll> > g[N];
ll safe[N];
ll wgt[N];
pair<ll,ll> edge[N];

ll mod_pow ( ll a , ll b ) {
    if (b == 0) return 1;
    if (b == 1) return (a % mod);
    if (b == 2) return ((a % mod) * (a % mod)) % mod;
    return ((mod_pow(mod_pow(a, (b >> 1)), 2) * mod_pow(a, (b & 1))) % mod);
}

void diskxtas(vector<ll> &dis,ll st) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    ll vis[N] = {false};
    pq.push({0, st});
    dis[st] = 0;
    while (!pq.empty()) {
        ll weit = pq.top().first, nd = pq.top().second;
        pq.pop();
        if (vis[nd])
            continue;
        vis[nd] = true;
        for (ll i = 0; i < g[nd].size(); i++) {
            ll now = weit + wgt[g[nd][i].second];
            if (now < dis[g[nd][i].first]) {
                dis[g[nd][i].first] = now;
                pq.push({dis[g[nd][i].first], g[nd][i].first});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v >> wgt[i] >> safe[i];
        g[u].pb({v, i});
        g[v].pb({u, i});
        edge[i] = {u, v};
    }

    ll st, ed;
    cin >> st >> ed;
    vector<ll> disSt(n + 2, inf);
    vector<ll> disEd(n + 2, inf);
    diskxtas(disSt, st);
    diskxtas(disEd, ed);

    ll req = disSt[ed];
    if (req == inf) {
        cout << "Stay safe, stay indoors\n";
        return;
    }
    ll cnt = 0, maxx = 0, tot = 0;
    for (ll i = 0; i < m; i++) {
        ll u = edge[i].first, v = edge[i].second;
        ll dis = min(disSt[u] + wgt[i] + disEd[v], disSt[v] + wgt[i] + disEd[u]);
        if (dis == req) {
            if (safe[i] > maxx) {
                maxx = safe[i];
                cnt = 1;
            } else if (safe[i] == maxx) {
                cnt++;
            }
            tot++;
        }
    }
    ll up = cnt;
    ll down = tot;
    ll tp = mod_pow(down, mod - 2);
    tp = (tp * up) % mod;
    cout << maxx << " " << tp << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
//    cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
