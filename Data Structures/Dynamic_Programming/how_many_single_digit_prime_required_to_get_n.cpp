/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/lets-begin/
Learning:https://www.geeksforgeeks.org/minimum-number-of-single-digit-primes-required-whose-sum-is-equal-to-n/
*/

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
const long int MAXN=1000005;
long int dp[MAXN];
/*==========================================FUNCTIONS====================================*/
void pre(){
    for(long int i=1;i<MAXN;i++)
        dp[i]=1e9;
    dp[0]=dp[2]=dp[3]=dp[5]=dp[7]=1;
    for(long int i=1;i<MAXN;i++){
        if(i>=7)
            dp[i]=min(dp[i],1+dp[i-7]);
        if(i>=5)
            dp[i]=min(dp[i],1+dp[i-5]);
        if(i>=3)
            dp[i]=min(dp[i],1+dp[i-3]);
        if(i>=2)
            dp[i]=min(dp[i],1+dp[i-2]);
    }
}
void solve() {
  long int n;
  cin>>n;
  if(dp[n]==1e9) cout<<"-1";
  else cout<<dp[n];
}
/*==========================================MAIN====================================*/
int main() {
//        ios_base::sync_with_stdio(false);
//        cin.tie(NULL);
    pre();
    long int t;
    cin >> t;
    while (t--) {
        solve();
        cout<<endl;
    }
    return 0;
}

