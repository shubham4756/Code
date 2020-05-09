/*
Link:- https://codeforces.com/contest/1108/problem/E2
Link:- https://codeforces.com/contest/1108/problem/E1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int Mod=1e9+7;
const int N=1e5+10,M=310;
long int n,m;
long int a[N],b[N],l[M],r[M],rec,ans;
set<long int > key;
void solve() {
    cin >> n >> m;
    for (long int i = 1; i <= n; i++) cin >> a[i];
 
    for (long int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        key.insert(l[i]);
        key.insert(r[i] + 1);
    }
    ans = *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1);
    for (auto it = key.begin(); it != key.end(); it++) {
        long int i = *it;
        memset(b, 0, sizeof(b));
        long int mx = -1e9, mi = 1e9, sum = 0;
        for (long int j = 1; j <= m; j++) {
            if (l[j] <= i && i <= r[j])
                continue;
            b[l[j]]--;
            b[r[j] + 1]++;
        }
        for (long int j = 1; j <= n; j++) {
            sum += b[j];
            mx = max(mx, a[j] + sum);
            mi = min(mi, a[j] + sum);
        }
        //cout<<mx<<" "<<mi<<endl;
        if (mx - mi > ans) {
            rec = i;
            ans = mx - mi;
        }
    }
    cout << ans << endl;
    if (rec) {
        vector<long int> res;
        for (long int i = 1; i <= m; i++) {
            if (l[i] <= rec && rec <= r[i]) continue;
            res.push_back(i);
        }
        cout << res.size() << endl;
        for (long int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    } else {
        cout << "0\n";
    }
}
int main() {
//    long int t;
//    cin >> t;
//    while (t--)
        solve();
}
