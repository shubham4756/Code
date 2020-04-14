/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/gaurav-and-subarray-3-787fb90a/
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//const long MAXN=100;
typedef long long int ll;
void solve() {
    ll n,q;
    cin>>n>>q;
    ll a[n+1];
    a[0]=0;
    for(ll i=0;i<n;i++){
        long x,cnt=0;
        cin>>x;
        while(x){
            if(x&1)
                cnt++;
            x/=2;
        }
        a[i+1]=a[i]+cnt;
    }
    while(q--){
        ll l=1,r=1;
        ll k,minn=LLONG_MAX;
        cin>>k;
        while(l<=r && r<=n){
            if(a[r]-a[l-1]>=k){
                minn=min(minn,r-l+1);
                l++;
            } else
                r++;
        }
        if(minn==LLONG_MAX)
            cout<<"-1\n";
        else
            cout<<minn<<endl;
    }
}
int main() {
//     long t;
//     cin>>t;
//     while(t--)
        solve();
    return 0;
}
