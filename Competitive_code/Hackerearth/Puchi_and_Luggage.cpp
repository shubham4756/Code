/*
Link: https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/puchi-and-luggage/
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        vector<int>::iterator it,tp;
        for (int i = 0; i < n; i++) {
            it = lower_bound(v.begin(), v.end(), a[i]);
            tp=it;
             int ans= (int) (it - v.begin());
             cout<<ans<<" ";
            v.erase(tp);
        }
        //v.clear();
        cout<<endl;
    }
    return 0;
}
