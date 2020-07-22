/*
Link:https://www.codechef.com/COOK118B/problems/CROADS
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

	void solve() {
		ll n;
		cin>>n;
		ll tp=n,st=0;
		while(tp){
			st+=(tp&1);
			tp/=2;
		}
		if(st==1){
			cout<<"-1\n";
			return ;
		}
		ll ans=0;
		for(ll i=1;i<=n;i<<=1){
			ans+=((n-i)/(i<<1))*i;
		}
		for (ll i = 2; i < n;i<<=1){
			ans+=i;
		}
		cout<<ans<<endl;
	}
	
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}
