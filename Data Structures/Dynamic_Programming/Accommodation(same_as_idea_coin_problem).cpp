/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/accomodation-a5c006f3/
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
/*==========================================FUNCTIONS====================================*/
void solve(){
    long int m,n;
    cin>>m>>n;
    long int dp[n+1][m];
    long int a[m];
    for(long int i=0;i<m;i++) {
        cin >> a[i];
        dp[0][i]=1;
    }
    for(long int i=1;i<=n;i++){
        for(long int j=0;j<m;j++) {
            long int x = ((i - a[j])>=0)?dp[i-a[j]][j]:0;
            long int y=(j>=1)?dp[i][j-1]:0;
            dp[i][j]=(x+y)%Mod;
        }
    }
    cout<<dp[n][m-1]<<endl;
}
/*==========================================MAIN====================================*/
int main() {
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
//    long int t;
//    cin>>t;
    solve();
    return 0;
}
