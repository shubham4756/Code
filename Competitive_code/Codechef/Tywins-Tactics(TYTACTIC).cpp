/*
Link: https://www.codechef.com/problems/TYTACTIC
*/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long int
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";

typedef tree < int ,null_type ,less<int>,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int  MOD=1000000007;
const int N=100005 * 2;
const int INF = 1e9;

vector< ll > g[N];
stack< ll > st;
map< ll,ll > mp;
ll tr[N],cost[N],child[N],n,q;

ll dfs(ll nd,ll pt) {
    ll xx=1;
    for(ll it:g[nd]) {
        if (it != pt)
            xx += dfs(it, nd);
    }
    st.push(nd);
    return child[nd]=xx;
}

void add(ll k,ll val) {
    while (k <= n) {
        tr[k] += val;
        k += k & -k;
    }
}

ll sum(ll k) {
    ll res = 0;
    while (k >= 1) {
        res += tr[k];
        k -= (k & -k);
    }
    return res;
}

void solve() {
    memset(tr, 0, sizeof(tr));
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        cin >> cost[i];
    for (ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1, 0);

    while (!st.empty()) {
        mp[st.top()] = n + 1 - st.size();
        add(n + 1 - st.size(), cost[st.top()]);
        st.pop();
    }

    while (q--) {
        char c;
        ll node;
        cin >> c >> node;
        if (c == 'U') {
            ll val;
            cin >> val;
            add(mp[node], val - cost[node]);
            cost[node] = val;
        } else {
            ll res = sum(mp[node] + child[node] - 1) - sum(mp[node] - 1);
            cout << res << endl;
        }
    }
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
