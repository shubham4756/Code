/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/ashu-and-prime-factors-4/
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
long int cnt[maxn];
void pre() {
    cnt[0] = cnt[1] = 0;

    for (long int i = 2; i < maxn; i++) {
        if (!cnt[i]) {
            for (long int j = 2 * i; j < maxn; j += i) {
                if (!cnt[j])
                    cnt[i]++;
                cnt[j] = 1;
            }
        }
    }
}
int main() {
    pre();
    long int t;
    cin >> t;
    while (t--) {
        long int n;
        cin >> n;
        cout << cnt[n] + 1 << endl;
    }
    return 0;
}
