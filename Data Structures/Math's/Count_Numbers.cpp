/*
Link:https://www.hackerearth.com/practice/math/combinatorics/inclusion-exclusion/practice-problems/algorithm/count-numbers-7/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
/*=============================================FUNCTIONS======================================*/
void solve(){
    long int k,t;
    cin>>k>>t;
    long int a[k];
    for(long int i=0;i<k;i++)
        cin>>a[i];
    vector<long long > v;
    for(long int i=1;i<(1<<k);i++){
        long long t=1;
        long int cnt=0;
        for(long int j=0;j<k;j++){
            if(i&(1<<j)){
                t*=a[j];
                cnt++;
            }
        }
        if(cnt%2==0)
            t*=-1;
        v.push_back(t);
    }
    while(t--){
        long int x,y;
        cin>>x>>y;
        long long ans=0;
        for(long int i=0;i<v.size();i++){
            long int tx=y/v[i],ty=(x-1)/v[i];
            ans+=tx-ty;
        }
        cout<<ans<<endl;
    }
}
/*==============================================MAIN============================================*/
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    long int t;
//    cin >> t;
//    while (t--)
        solve();
    return 0;
}
