/*
Link:https://www.hackerearth.com/practice/algorithms/string-algorithm/z-algorithm/practice-problems/algorithm/prefix-number-f5c76976/
Learning:https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/

/*==========================================FUNCTIONS====================================*/
void solve() {
    string s;
    cin >> s;
    long int n = s.size(), L = 0, R = 0, k;
    long int Z[n];
    Z[0] = 0;
    for (long int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R - L] == s[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    k = (n - 1) / 2;
    long int cnt = 0;
    for (long int i = 1; i <= k; i++) {
        if (Z[i] >= i)
            cnt++;
    }
    if (n % 2 == 0) {
        k = n / 2;
        if (s.substr(0, k) == s.substr(k, n - k))
            cnt++;
    }
    cout << cnt << endl;
}
/*==========================================MAIN====================================*/
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    long int t;
//    cin>>t;
//    while(t--)
       solve();
    return 0;
}

