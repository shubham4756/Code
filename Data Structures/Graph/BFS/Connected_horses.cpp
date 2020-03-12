/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/connected-horses-10/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[]={2,2,-2,-2,-1,-1,1,1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
void solve() {
    ll n, m, h, x, y;
    cin >> n >> m >> h;

    map<pair<ll, ll>, ll> mp;
    for (long int i = 0; i < h; i++) {
        ll x, y;
        cin >> x >> y;
        mp[{x, y}] = -1;
    }

    ll group = 1, i, j, maxx = INT_MIN;
    unordered_map<ll, ll> gpmember;

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second == -1) {
            queue<pair<ll, ll> > q;
            x = (it->first).first;
            y = (it->first).second;
            q.push({x, y});
            mp[{x, y}] = group;
            gpmember[group]++;
            while (q.size() > 0) {
                i = q.front().first;
                j = q.front().second;
                q.pop();
                for (int k = 0; k < 8; k++) {
                    pair<ll, ll> pos = {i + dx[k], j + dy[k]};
                    if (mp.find(pos) != mp.end() && mp[pos] == -1) {
                        mp[pos] = group;
                        gpmember[group]++;
                        q.push(pos);
                    }
                }
            }
            maxx = max(maxx, gpmember[group]);
            group++;
        }
    }

    vector<ll> fact(maxx + 1);
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i <= maxx; i++)
        fact[i] = (fact[i - 1] * i) % 1000000007;

    ll ans = 1;
    for (ll i = 1; i < group; i++)
        ans = (ans * fact[gpmember[i]]) % 1000000007;

    cout << ans << endl;
}
int main() {
    long int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
