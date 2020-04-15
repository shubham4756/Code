/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/4141/
Learning:https://www.geeksforgeeks.org/check-if-the-number-is-divisible-by-41-or-not-when-first-two-digits-are-given/
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//const long MAXN=100;
typedef long long int ll;
void solve() {
    ll ff, ss, c, n;
    cin >> ff >> ss >> c >> n;
    ll digit[n];
    digit[0] = ff;
    digit[1] = ss;
    for (ll i = 2; i < n; i++)
        digit[i] = (digit[i - 1] * c + digit[i - 2]) % 10;

    ll ans = digit[0];
    for (ll i = 1; i < n; i++)
        ans = (ans * 10 + digit[i]) % 41;

    if (ans % 41 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    long t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
