/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/once-upon-a-time-in-time-land/
*/


#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;

void solve() {
    int n, k;
    cin >> n >> k;
    long int a[n], dp[n] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[0] = a[0];
    for (int i = 1; i <= k; ++i) {
        dp[i] = max(dp[i - 1], a[i]);
    }
    for (int i = k + 1; i < n; ++i) {
        dp[i] = max(max(dp[i - k - 1] + a[i], dp[i - 1]), max(dp[i - k - 1], a[i]));
    }
    if (dp[n - 1] < 0)
        dp[n - 1] = 0;
    cout << dp[n - 1] << endl;
}
int main() {
//        ios_base::sync_with_stdio(false);
//        cin.tie(NULL);
    long int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
