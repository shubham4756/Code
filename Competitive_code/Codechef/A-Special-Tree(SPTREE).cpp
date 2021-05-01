#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 200010;

bool special[N],has[N];
vector< int > g[N];
int dep[N],point[N],specialNode[N];

void init() {
    memset(special, false, sizeof(special));
    for (int i = 0; i < N; i++) {
        g[i].clear();
        dep[i] = has[i] = point[i] = special[i] = specialNode[i] = 0;
    }
}

void dfs(int nd,int pt, int depth) {
    dep[nd] = depth;
    has[nd] |= special[nd];
    int spn = 0;
    for(int to:g[nd]) {
        if(to==pt)
            continue;
        dfs(to,nd,depth+1);
        has[nd] |= has[to];
        if(has[to]) spn = specialNode[to];
    }

    if(special[nd]) specialNode[nd] = nd;
    else specialNode[nd] = spn;
}

void BinaryLifting(int nd,int pt) {
    if(has[nd]) point[nd] = nd;
    else point[nd] = point[pt];
    for(int to:g[nd]) {
        if(to==pt)
            continue;
        BinaryLifting(to,nd);
    }
}

void solve() {
    int n, k, a;
    cin >> n >> k >> a;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        special[x] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(a, 0, 0);
    BinaryLifting(a, 0);
    pair<int, int> ans[n + 2];
    for (int i = 1; i <= n; i++)
        ans[i] = {2 * dep[point[i]] - dep[i], specialNode[point[i]]};

    for (int i = 1; i <= n; i++)
        cout << ans[i].first << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i].second << " ";
    cout << endl;
}

int main() {
    ll t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}
