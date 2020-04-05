/*
Link:https://codeforces.com/contest/699/problem/C
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/dhoni-and-holidays/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
/*==========================================FUNCTIONS====================================*/
void solve(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int dp[3][n+2];
    memset(dp,63, sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[0][i]=min(min(dp[0][i-1]+1,dp[1][i-1]+1),dp[2][i-1]+1);
        if(a[i]==1 || a[i]==3){
            dp[1][i]=min(dp[0][i-1],dp[2][i-1]);
        }
        if(a[i]==2 || a[i]==3){
            dp[2][i]=min(dp[0][i-1],dp[1][i-1]);
        }
    }
    cout<<min({dp[0][n],dp[1][n],dp[2][n]});
}
/*==========================================MAIN====================================*/
int main() {
    //  ios_base::sync_with_stdio(false);
    //  cin.tie(NULL);
 //   long int t;
 //   cin>>t;
//    while(t--)
        solve();
    return 0;
}
