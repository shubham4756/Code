/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/palindrome-count-1/
Learning:https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/
Learning:https://www.geeksforgeeks.org/count-palindrome-sub-strings-string-set-2/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
string s;
/*=============================================FUNCTIONS======================================*/
long int numberofpalindrome(){
    long int n=s.size();
    long int dp[n][n];
    bool p[n][n];
    memset(dp,0, sizeof(dp));
    memset(p,false, sizeof(p));
    for(long int i=0;i<n;i++)
        p[i][i]=true;

    for(long int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            p[i][i+1]=true;
            dp[i][i+1]=1;
        }
    }

    for(long int gap=2;gap<n;gap++){
        for(long int i=0;i<n-gap;i++){
            long int j=i+gap;
            if(s[i]==s[j] && p[i+1][j-1])
                p[i][j]=true;

             if(p[i][j]==true)
                 dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+1;
             else
                 dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
        }
    }
    return dp[0][n-1];
}
void solve(){
    cin>>s;
    long int ans=s.size()+numberofpalindrome();
    cout<<ans<<endl;
}
/*==============================================MAIN============================================*/
int main() {
//    long int t;
//    scanf("%ld",&t);
//    while (t--)
        solve();
    return 0;
}
