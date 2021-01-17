/*
Link: https://codeforces.com/contest/1076/problem/D
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
const int N=100005*3;

ll n,m,k;
vector< pair<ll, pair<ll,ll> > > vp[N];
vector<ll> last(N,-1),ans,d(N,inf);
set< pair<ll,ll> > st;

void solve() {
    cin >> n >> m >> k;
    for (ll i = 0; i < m; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        vp[x].pb({y, {w, i + 1}});
        vp[y].pb({x, {w, i + 1}});
    }
    st.insert({0, 1});
    d[1] = 0;
    while (!st.empty() && k > 0) {
        auto it = st.begin();
        st.erase(it);
        pair<ll, ll> p = *it;
        if (last[p.second] != -1) {
            k--;
            ans.push_back(last[p.second]);
        }
        for (pair<ll, pair<ll, ll> > pt: vp[p.second]) {
            ll dis = d[p.second] + pt.second.first;
            if (dis < d[pt.first]) {
                st.erase({d[pt.first], pt.first});
                d[pt.first] = dis;
                last[pt.first] = pt.second.second;
                st.insert({d[pt.first], pt.first});
            }
        }
    }
    n = ans.size();
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
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
