/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/hp-and-counting-number-of-ways-1d73a6a4/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
long int dp[102][100004];
/*==========================================FUNCTIONS====================================*/
void pre(){
    for(long int i=1;i<=100;i++) dp[i][1]=1;
    for(long int i=1;i<=100004;i++)  dp[1][i]=1;

    for(long int k=2;k<=100;k++){
        for(long int n=2;n<=10000;n++){
            if(n<=k)
               dp[k][n]+=1;
            for(long int x=1;x<=k;x++){
                if(n-x>0)
                    dp[k][n]=(dp[k][n]+dp[k][n-x])%Mod;
            }
        }
    }
}
void solve(){
    long int n,k;
    cin>>n>>k;
//    for(long int i=1;i<=k;i++){
//        for(long int j=1;j<=n;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    cout<<dp[k][n]<<endl;
}
/*==========================================MAIN====================================*/
int main() {
    pre();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

