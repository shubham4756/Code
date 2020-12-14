/*
Link: https://codeforces.com/contest/1453/problem/C
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2002;
char a[N][N];
ll n;
ll Fn(ll x) {
    return max(n - 1 - x, x);
}
void Find(char c) {
    vector<ll> left(n, 1e9), right(n, -1e9), up(n, 1e9), down(n, -1e9);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (a[i][j] == c) {
                left[i] = min(left[i], j);
                right[i] = max(right[i], j);
                up[j] = min(up[j], i);
                down[j] = max(down[j], i);
            }
        }
    }
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (down[i] >= up[j])
                res = max(res, (down[i] - up[j]) * max(Fn(i), Fn(j)));
            if (right[i] >= left[j])
                res = max(res, (right[i] - left[j]) * max(Fn(i), Fn(j)));
        }
    }
    cout << res << " ";
}
void solve() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < 10; i++)
        Find((char) (i + '0'));
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
