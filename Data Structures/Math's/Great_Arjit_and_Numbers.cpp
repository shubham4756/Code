/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/great-arjit-and-numbers/
*/

#include<bits/stdc++.h>
using namespace std;
long long int modInv(long long int x,int n,int mod) {
    long int res = 1;
    while (n) {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n = n >> 1;
    }
    return res;
}
void solve() {
    long int n, Mod = 1000000007;
    cin >> n;
    long int a[n], arr[n - 1];
    for (long int i = 0; i < n; i++) {
        cin >> a[i];
        if (i >= 1)
            arr[i - 1] = ((a[i] % Mod) * (modInv(a[i - 1], Mod - 2, Mod) % Mod)) % Mod;
    }
    long int sum1 = 0;
    for (long int i = 0; i < n - 1; i++) {
        //cout<<arr[i]<<" ";
        long int tp = (arr[i] % Mod * (arr[i] + 1) % Mod * modInv(2, Mod - 2, Mod)) % Mod;
        sum1 = (sum1 + tp) % Mod;
    }
    long int tp = (sum1 % Mod * (sum1 + 1) % Mod * modInv(2, Mod - 2, Mod)) % Mod;
    cout << tp << endl;
}
int main() {
    long int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
