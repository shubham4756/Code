/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/beautiful-primes/
Learning:https://math.stackexchange.com/questions/163245/finding-sum-of-factors-of-a-number-using-prime-factorization
         http://mathforum.org/library/drmath/view/71550.html
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAXN 1000001;
typedef long long int ll;
ll ModInv(ll x,ll n){
    ll tp=1;
    while(n){
        if(n&1)
            tp=(tp*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return tp;
}
void solve() {
    long N;
    scanf("%lld",&N);
    ll a[N],b[N];
    for(long i=0;i<N;i++)
        scanf("%lld",&a[i]);
    for(long i=0;i<N;i++)
        scanf("%lld",&b[i]);

    long long ans=1;
    for(long i=0;i<N;i++){
        ll p=a[i],n=b[i]+1;
        ll xx=(ModInv(p,n)-p+mod)%mod;
        xx=(xx*ModInv(p-1,mod-2))%mod;
        //cout<<xx<<endl;
        ans=(ans*xx)%mod;
    }
    cout<<ans<<endl;
}
int main() {
     long t;
     cin>>t;
     while(t--)
    solve();
    return 0;
}
