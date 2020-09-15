/*
Link : https://www.codechef.com/SEPT20A/problems/FINXOR
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
template<typename T> istream &operator>>(istream &is, vector<T> &vec)
                                        { for (auto &v : vec) is >> v; return is; }

const int  MOD=1000000007;
const int N=100005;

int main() {
    long int t;
    cin>>t;
    while(t--){
    	long n;
    	cin>>n;
    	ll ans=0;
    	ll sum;
    	cout<<"1 "<<(1LL<<20)<<endl;
    	cin>>sum;
    	sum-=(1LL<<20)*n;
    	if(sum%2) ans=1;
    	for(ll i=1;i<=19;i++){
    		cout<<"1 "<<(1LL<<i)<<endl;
    		ll sum1;
    		cin>>sum1;
    		ll diff=sum-sum1;
    		diff=diff/(1LL<<i);
    		ll on=(n+diff)/2;
    		if(on%2) ans=ans|(1LL<<i);
    	}
    	cout<<"2 "<<ans<<endl;
    	int j;
    	cin>>j;
    	if(j==-1)
    		return 0;
    }
    return 0;
}
