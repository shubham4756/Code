/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/
*/

#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
long int fact[100005];
long int modExp(long int x,long int n) {
    long int result = 1;
    while (n > 0) {
        if (n % 2 == 1)
            result = (result * x) % Mod;
        x = (x * x) % Mod;
        n = n / 2;
    }
    return result % Mod;
}
void pre() {
    fact[0] = fact[1] = 1;
    for (long int i = 2; i < 100005; i++)
        fact[i] = (fact[i - 1] * i) % Mod;
}
int main() {
    pre();
    long int t;
    cin >> t;
    while (t--) {
        long int n, k;
        cin >> k >> n;
        cout << (fact[n] * modExp(fact[n - k], Mod - 2)) % Mod << endl;
    }
}
