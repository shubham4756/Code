/*
Link : https://codeforces.com/contest/1337/problem/D
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

ll Ans;
ll Get(ll x,ll y,ll z){
	ll res=(x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z);
	return res;
}

void FindAns(vector<ll> r,vector<ll> g,vector<ll> b){
	for(int i=0;i<r.size();i++){
		ll x=r[i];
		long iy=lower_bound(all(g),x)-g.begin();
		long iz=upper_bound(all(b),x)-b.begin();
		if (iy<0 || iy>=g.size() || iz<=0 || iz>b.size())  
			continue; 
        iz--;
        Ans = min(Ans,Get(x,g[iy],b[iz]));
    }
}

void solve(){
	ll R,G,B;
	cin>>R>>G>>B;
	vector<ll> red(R),green(G),blue(B);
	for(int i=0;i<R;i++) cin>>red[i];
	for(int i=0;i<G;i++) cin>>green[i];
	for(int i=0;i<B;i++) cin>>blue[i];
	sort(all(red)); sort(all(green)); sort(all(blue));
	Ans=9e18;
	FindAns(red,green,blue); FindAns(red,blue,green);
	FindAns(blue,green,red); FindAns(blue,red,green);
	FindAns(green,red,blue); FindAns(green,blue,red);
	cout<<Ans<<endl;
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
