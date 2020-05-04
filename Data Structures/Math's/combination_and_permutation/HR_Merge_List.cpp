/*
Link:https://www.hackerrank.com/challenges/merge-list/problem
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll fact[205];
ll ModInv(ll x,ll n){
    ll res=1;
    while (n){
        if(n&1){
            res=(res*x)%MOD;
        }
        x=(x*x)%MOD;
        n=n/2;
    }
    return res%MOD;
}
int main() {
    fact[0]=1;
    fact[1]=1;
    for(long int i=2;i<=200;i++)
        fact[i]=(fact[i-1]*i)%MOD;
    long int t;
    cin>>t;
    while(t--){
        long int n,m;
        cin>>n>>m;
        ll ans=((fact[n+m]*ModInv(fact[n],MOD-2))%MOD*ModInv(fact[m],MOD-2))%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
