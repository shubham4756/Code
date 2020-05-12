/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/yogi-and-his-steps-65b27a4b/
Link:https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long int CeilIndex(vector<long int> &tt,long int l,long int r,long int key) {
    while (r - l > 1) {
        long int m = l + (r - l) / 2;
        if (tt[m] > key)
            r = m;
        else
            l = m;
    }
    return r;
}
long int findLongestIncresing(vector<long int> &v) {
    vector<long int> tt(v.size(), 0);
    long int len = 1;
    tt[0] = v[0];
    for (long int i = 1; i < v.size(); i++) {
        if (v[i] < tt[0])
            tt[0] = v[i];
        else if (v[i] > tt[len - 1])
            tt[len++] = v[i];
        else {
            tt[CeilIndex(tt, -1, len - 1, v[i])] = v[i];
        }
    }
    return len;
}
void solve() {
    long int n;
    cin >> n;
    vector<long int> v1(n), v2(n);
    for (long int i = 0; i < n; i++) {
        cin >> v1[i];
        v2[i] = v1[i];
    }
    reverse(v2.begin(), v2.end());
    cout << n - max(findLongestIncresing(v1), findLongestIncresing(v2)) << endl;
}
int main() {
    solve();
}
