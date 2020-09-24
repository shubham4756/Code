/*
Link : https://codeforces.com/contest/1420/problem/C2
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

void solve(){
	ll n,q;
	cin>>n>>q;
	vector<ll> v(n+2,0);
	for(int i=1;i<=n;i++)
		cin>>v[i];
	ll ans=0;
	for(int i=1;i<=n-1;i++)
		ans+=max(v[i]-v[i+1],(ll)0);
	cout<<ans+v[n]<<endl;
	while(q--){
		ll x,y;
		cin>>x>>y;
		if(x==y){
			cout<<ans+v[n]<<endl;
			continue;
		}
		if(x-1) ans-=max(v[x-1]-v[x],(ll)0);
		if(x+1<=n) ans-=max(v[x]-v[x+1],(ll)0);
		if(y-1>=1 && y-1!=x) ans-=max(v[y-1]-v[y],(ll)0);
		if(y+1<=n) ans-=max(v[y]-v[y+1],(ll)0);
		swap(v[x],v[y]);
		if(x-1) ans+=max(v[x-1]-v[x],(ll)0);
		if(x+1<=n) ans+=max(v[x]-v[x+1],(ll)0);
		if(y-1>=1 && y-1!=x) ans+=max(v[y-1]-v[y],(ll)0);
		if(y+1<=n) ans+=max(v[y]-v[y+1],(ll)0);
		cout<<ans+v[n]<<endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
