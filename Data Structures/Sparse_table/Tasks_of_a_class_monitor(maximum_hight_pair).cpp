/*
Link:https://www.hackerearth.com/problem/algorithm/class-monitor-c76dc24a/description/?layout=old
submission1:https://www.hackerearth.com/challenges/competitive/june-easy-20/algorithm/class-monitor-c76dc24a/submission/42906185/
submission2:https://www.hackerearth.com/challenges/competitive/june-easy-20/algorithm/class-monitor-c76dc24a/submission/42906908/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Md=1e9+7;

const int MAXN=1e6+5;
const int LIM=21;

vector<int> v;
int lg[MAXN];
int p2[LIM];
int RMG[LIM][MAXN];

void preprocess() {
    int n = v.size();
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    p2[0]=1;
    for (int i = 0; i < n; i++)
        RMG[0][i] = v[i];

    for (int i = 1; i <= lg[n]; i++) {
        p2[i] = 1 << i;
        int x = n - p2[i], y = p2[i - 1];
        for (int j = 0; j <= x; j++)
            RMG[i][j] = max(RMG[i - 1][j], RMG[i - 1][j + y]);
    }
}
int query(int l,int r){
    int x=lg[r-l+1];
    return max(RMG[x][l],RMG[x][r-p2[x]+1]);
}
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    preprocess();

    int ans=0;
    for(int i=0;i<n;i++){
        int low=i,high=n-1,mxId=i;
        while(low<=high) {
            int mid = (low + high) / 2;
            int xx = query(i,mid);
            if (xx - v[i] <= k) {
                mxId = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans+=mxId-i+1;
    }
    cout<<ans<<endl;
}
int32_t main() {
    solve();
    return 0;
}
