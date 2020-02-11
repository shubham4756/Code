/*
Link:https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/yet-to-keep-6f89250c/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    long int n,q,i;
    cin>>n>>q;
    ll a[n];
    for(i=0;i<n;i++) cin>>a[i];

    vector<pair<ll,ll> > na;
    sort(a,a+n);
    na.push_back({INT_MIN,a[0]-1});
    for(i=1;i<n;i++)
    {
        if(a[i]-a[i-1]>1){
            na.push_back({a[i-1]+1,a[i]-1});
        }
    }
    na.push_back({a[n-1]+1,INT_MAX});
    ll len=na.size();
    while(q--){
        ll x;
        cin>>x;
        ll val=x+1;
        ll l=0,r=len-1,mid;
        ll flag=-1;
        while(l<=r){
            mid=(l+r)/2;
            ll f=na[mid].first,s=na[mid].second;
            if(val>=f && val<=s)
            {
                flag=mid;
                break;
            }
            else if(val<f){
                flag=mid;
                r=mid-1;
            }
            else if(val>s){
                l=mid+1;
            }
        }
        ll f=na[flag].first,s=na[flag].second;
        if(val>=f && val<=s)
            cout<<val<<endl;
        else
            cout<<f<<endl;
    }
    return 0;
}
