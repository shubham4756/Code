/*
Link : https://codeforces.com/contest/1213/problem/G
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
const int N=1000010;

ll res=0;
ll parent[N],sz[N];

ll FindPairs(ll x) {
    return (x * (x + 1) * 1LL) / 2LL;
}

ll Root(ll x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = Root(parent[x]);
}

void MK_union(ll x,ll y) {
    x = Root(x);
    y = Root(y);
    if (sz[y] > sz[x])
        swap(x, y);
    parent[y] = x;
    res -= FindPairs(sz[x]);
    res -= FindPairs(sz[y]);
    sz[x] += sz[y];
    res += FindPairs(sz[x]);
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (long i = 0; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    vector<pair<ll, pair<ll, ll> > > e(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> e[i].se.fi >> e[i].se.se >> e[i].fi;
    }
    vector<pair<ll, ll> > q(m);
    vector<ll> ans(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].fi;
        q[i].se = i;

    }
    sort(e.begin(), e.end());
    sort(q.begin(), q.end());
    long pos = 0;
    for (int i = 0; i < m; i++) {
        while (pos < n - 1 && e[pos].fi <= q[i].fi) {
            ll x = e[pos].se.fi, y = e[pos].se.se;
            MK_union(x, y);
            pos++;
        }
        ans[q[i].se] = res;
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
