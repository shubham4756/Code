/*
Link:https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/monk-and-monster-1acbb78c/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/

/*==========================================FUNCTIONS====================================*/
void solve() {
    string s,a;
    cin>>s;
    long int n,m;
    cin>>a;
    m=a.size();
    cin>>n;
    long int cost[n];
    for(long int i=0;i<n;i++){
        cin>>cost[i];
        if(i>n-m)
            cost[i]=0;
    }
    for(long int i=0;i<=n-m;i++){
        if(s.substr(i,m)!=a)
            cost[i]=0;
    }
    long int dp[n+1]={0};
    dp[0]=cost[0];
    for(long int i=1;i<n;i++){
        if(cost[i]==0){
            dp[i]=max(dp[i],dp[i-1]);
        }
        else if(i-m<0){
            dp[i]=max({dp[i],dp[i-1],cost[i]});
        }else{
            dp[i]=max({dp[i-1],dp[i-m]+cost[i]});
        }
    }
   // for(long int i=0;i<n;i++)
    //    cout<<dp[i]<<" ";
   // cout<<endl;
    cout<<dp[n-1]<<endl;
}
/*==========================================MAIN====================================*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t;
    cin>>t;
    while(t--)
       solve();
    return 0;
}
