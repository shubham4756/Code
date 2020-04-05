/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/tower-of-hanoi-17/
see comment for more info
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
/*==========================================FUNCTIONS====================================*/
void solve(){
    long int n;
    cin>>n;
    vector<pair<ll,ll> > v;
    for(long int i=0;i<n;i++){
        ll r,h;
        cin>>r>>h;
        v.push_back({h,r});
    }
    sort(v.begin(),v.end());
    vector<pair<ll,ll> > dp;
    for(long int i=0;i<n;i++)
        dp.push_back({v[i].second,0});

    for(long int i=0;i<n;i++){
        ll val=v[i].second,res=0;
        for(long int j=0;j<i;j++){
            if(v[i].first==v[j].first){
                break;
            }else{
                if(dp[j].first<val){
                    res=max(res,dp[j].second);
                }
            }
        }
        dp[i].second=max(dp[i].second,res+v[i].first);
    }
    ll fin=INT_MIN;
    for(long int i=0;i<n;i++)
        fin=max(fin,dp[i].second);

    cout<<fin<<endl;
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

