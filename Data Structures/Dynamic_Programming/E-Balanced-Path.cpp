/*
Link: https://atcoder.jp/contests/abc147/tasks/abc147_e
*/

/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
const int  MOD=1000000007;
const int N=100010;

bool dp[85][85][13000];

void solve() {
    int h,w;
    cin>>h>>w;
    int a[h][w],b[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            cin>>b[i][j];
    }
    int g[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            g[i][j]=abs(a[i][j]-b[i][j]);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0 && j==0) dp[0][0][g[0][0]]=true;
            if(i){
                for(int k=0;k<13000;k++){
                    if(dp[i-1][j][k]){
                        dp[i][j][abs(k+g[i][j])]=true;
                        dp[i][j][abs(k-g[i][j])]=true;  
                    }
                }
            }
            if(j){
                for(int k=0;k<13000;k++){
                    if(dp[i][j-1][k]){
                        dp[i][j][abs(k+g[i][j])]=true;
                        dp[i][j][abs(k-g[i][j])]=true;
                    }
                }
            }
        }
    }
    for(int k=0;k<13000;k++){
        if(dp[h-1][w-1][k]){
            cout<<k<<endl;
            return ;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
