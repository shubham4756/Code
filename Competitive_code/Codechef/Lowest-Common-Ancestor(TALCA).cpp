#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define pb push_back
const int N=100005 * 2;
vector<int> g[N];
int n, l;
int lev[N];
int up[N][21];

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i <= l; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (int it : g[v]) {
        if (it != p) {
            lev[it] = lev[v] + 1;
            dfs(it, v);
        }
    }
}

int lca(int u,int v) {
    if (lev[u] < lev[v])
        swap(u, v);
    for (int i = l; i >= 0; i--)
        if (lev[u] >= (lev[v] + (1LL<<i)))
            u = up[u][i];
    if (u == v)
        return u;
    for (int i = l; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int dist (int u,int v) {
    int x = lca(u, v);
    int res = lev[u] + lev[v] - 2 * lev[x];
    return res;
}

void solve() {
    cin >> n;
    l = (int) ceil(log2(n));
    for (ll i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    lev[1] = 1;
    dfs(1, 1);
    int Q;
    cin >> Q;
    pair<int, int> p[6];
    for (int i = 0; i < Q; i++) {
        int r, u, v;
        cin >> r >> u >> v;
        p[0].second = u;
        p[1].second = v;
        p[2].second = r;
        p[3].second = lca(r, u);
        p[4].second = lca(r, v);
        p[5].second = lca(u, v);

        for (int i = 0; i < 6; i++) {
            int x = p[i].second;
            p[i].first = dist(x, r) + dist(x, u) + dist(x, v);
        }
        sort(p, p + 6);
        cout << p[0].second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
