/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/uniformity-794d7bdc/

learning Link:https://www.geeksforgeeks.org/maximum-length-substring-having-all-same-characters-after-k-changes/
*/

#include<bits/stdc++.h>
using namespace std;
long int maxlen(string a,long int n,long int k,char c) {
    long int cnt = 0, ans = 1;
    long int l = 0, r = 0;
    while (r < n) {
        if (a[r] != c)
            cnt++;
        while (cnt > k) {
            if (a[l] != c)
                cnt--;
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}
int main() {
    long int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    cout << max(max((long int) 1, maxlen(a, n, k, 'a')), max(maxlen(a, n, k, 'b'), maxlen(a, n, k, 'c')));
    return 0;
}
