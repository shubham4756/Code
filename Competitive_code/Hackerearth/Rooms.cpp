/*
Link: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/rooms-1/description/
EDITORIAL: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/rooms-1/editorial/?layout=old 
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
const int N=100005;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll> > vp;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++) {
        ll y;
        cin >> y;
        vp.pb({a[i], a[i] + y});
    }
    sort(all(vp));
    min_heap<ll> pq;
    pq.push(vp[0].S);
    ll res = 1;
    for (ll i = 1; i < vp.size(); i++) {
        if (vp[i].F >= pq.top())
            pq.pop();
        else
            res++;
        pq.push(vp[i].S);
    }
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
    cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}
