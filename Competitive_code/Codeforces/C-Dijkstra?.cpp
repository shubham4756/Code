/*
Link: https://codeforces.com/contest/20/problem/C
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
#define inf 9223372036854775807
template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int  MOD=1000000007;
const int N=100005;

ll n,m;
vector< pair<ll,ll> > vp[N];
vector< ll > dis(N,inf);
vector< bool > vis(N,false);
vector<ll> parent(N);

void Dijkstra() {
    // sum of dis, current node, parent node
    min_heap<pair<ll, pair<ll, ll> > > pq;
    pq.push({0, {1, 0}});
    while (!pq.empty()) {
        pair<ll, pair<ll, ll> > p = pq.top();
        pq.pop();
        if (vis[p.S.F])
            continue;
        vis[p.S.F] = true;
        parent[p.S.F] = p.S.S;
        for (pair<ll, ll> nd : vp[p.S.F]) {
            if (!vis[nd.F] && dis[nd.F] > p.F + nd.S) {
                dis[nd.F] = p.F + nd.S;
                pq.push({dis[nd.F], {nd.F, p.S.F}});
            }
        }
    }
    stack<ll> ans;
    ll x = n;
    while (x != 0) {
        ans.push(x);
        if (dis[x] == inf) {
            cout << "-1";
            return;
        }
        x = parent[x];
    }
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        vp[x].pb({y, w});
        vp[y].pb({x, w});
    }
    dis[1] = 0;
    Dijkstra();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
//    cin>>t;                     // DON'T FORGET IT. ^^^
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}
