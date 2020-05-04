/*
Link:https://www.hackerrank.com/challenges/shashank-and-list/problem
good explanation in discussions
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll power(ll x,ll n){
    ll res=1;
    while(n){
        if(n&1){
            res=(res*x)%MOD;
        }
        x=(x*x)%MOD;
        n=n/2;
    }
    return res;
}
int main() {
        long int n;
        cin>>n;
        ll a;
        vector<ll> v;
        for(long int i=0;i<n;i++) {
            cin>>a;
            v.push_back((1+power(2,a))%MOD);
        }
        ll ans=1;
        for(long int i=0;i<v.size();i++){
            ans=((ans%MOD)*(v[i]%MOD))%MOD;
        }
        cout<<ans-1;
    return 0;
}
