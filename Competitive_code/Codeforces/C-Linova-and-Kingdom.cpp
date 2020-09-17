/*
Link : https://codeforces.com/contest/1337/problem/C
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
const int N=1000005;

int n,k;
vector<int> T[N];
vector<int> Dep(N,0),Child(N,0);

void dfs(int Nd,int Pt,int Dp){
	Dep[Nd]=Dp;
	Child[Nd]=1;
	for(int i=0;i<T[Nd].size();i++){
		if(T[Nd][i]!=Pt){
			dfs(T[Nd][i],Nd,Dp+1);
			Child[Nd]+=Child[T[Nd][i]];
		}
	}
}

void solve(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		long u,v;
		cin>>u>>v;
		T[u].pb(v);
		T[v].pb(u);
	}
	dfs(1,-1,1);
	vector<int> v;
	for(int i=1;i<=n;i++){
		v.pb(Dep[i]-Child[i]);
	}
	sort(v.rbegin(),v.rend());
	ll ans=0;
	for(int i=0;i<k;i++)
		ans+=v[i];
	cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
