/*
Link: https://www.codechef.com/BYTR20B/problems/RICY/
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

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &v : vec) is >> v;
    return is;
}

template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int MOD = 1000000007;
const int N = 10005;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll a[n + 2], b[m];
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    vector<ll> v;
    v.pb(LLONG_MIN);
    for (ll i = 1; i < m; i++) {
        ll mn = LLONG_MAX;
        for (ll j = b[i - 1]; j <= b[i]; j++)
            mn = min(mn, a[j]);
        v.pb(mn);
    }
    n = v.size();
    vector<ll> prId(n + 1), nxId(n + 1);
    prId[0] = 0;
    stack<ll> st;
    st.push(0);
    for (ll i = 1; i < n; i++) {
        while (v[i] < v[st.top()]) {
            st.pop();
        }
        prId[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    v.pb(LLONG_MIN);
    st.push(n);
    nxId[n] = n;
    for (ll i = n - 1; i >= 1; i--) {
        while (v[i] <= v[st.top()])
            st.pop();
        nxId[i] = st.top();
        st.push(i);
    }
    ll res = 0;
    for (ll i = 1; i < n; i++)
        res += v[i] * (i - prId[i]) * (nxId[i] - i);
    for (ll i = 0; i < m; i++)
        res += a[b[i]];
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    cin >> t;                     // DON'T FORGET IT. ^^^
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
