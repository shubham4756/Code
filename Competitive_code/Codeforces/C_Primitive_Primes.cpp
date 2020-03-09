/*
Link: http://codeforces.com/contest/1316/problem/C
*/


#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n, m, k;
    cin >> n >> m >> k;
    long long int x, idx1 = LONG_LONG_MAX, idx2 = LONG_LONG_MAX;
    for (long long int i = 0; i < n; i++) {
        cin >> x;
        if (x % k != 0)
            idx1 = min(idx1, i);
    }
    for (long long int i = 0; i < m; i++) {
        cin >> x;
        if (x % k != 0)
            idx2 = min(idx2, i);
    }
    cout << idx1 + idx2 << endl;
    return 0;
}
