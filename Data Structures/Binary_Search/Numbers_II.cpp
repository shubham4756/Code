/*
Link:https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/hp-and-numbers-ii-0115b16e/
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//const long MAXN=100;
typedef long long int ll;
void solve() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll l = min(a, b), r = max(a, b) * n;
    ll lcm = (a * b) / __gcd(a, b), m;
    while (l < r) {
        m = (r + l) / 2;
        ll k = m / a + m / b - m / lcm;
        if (k < n)
            l = m + 1;
        else if (k > n)
            r = m;
        if (k == n)
            break;
    }
    if (m % a != 0 && m % b != 0)
        m = m - min(m % a, m % b);
    cout << m << endl;
}
int main() {
    long t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
