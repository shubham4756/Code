/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/help-patwari/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
/*==========================================FUNCTIONS====================================*/
void solve(){
    long int k;
    cin>>k;
    long int dp[k+1];
    dp[0]=0;
    dp[1]=1;
    for(long int i=2;i<=k;i++){
        dp[i]=(dp[i-1]+dp[i-2])%Mod;
    }
    cout<<dp[k]<<endl;
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
