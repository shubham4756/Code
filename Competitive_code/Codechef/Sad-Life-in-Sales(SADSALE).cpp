/*
Link : https://www.codechef.com/CSEI2021/problems/SADSALE/
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";

template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int  MOD=1000000007;
const int N=100005;

ll n, l;
vector<vector<ll>> adj;

ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;

void dfs(ll v, ll p){
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(ll root,ll n) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<ll>(l + 1));
    dfs(root, root);
}

void DFS(ll nd,ll pt,vector< pair<ll,ll> > gp[],vector<ll>& val,ll res){
	val[nd]=res;
	for(int i=0;i<gp[nd].size();i++){
		if(gp[nd][i].F!=pt){
			DFS(gp[nd][i].F,nd,gp,val,res+gp[nd][i].S);
		}
	}
}

void solve(){
	ll n,q,r;
	cin>>n>>q>>r;
	vector< pair<ll,ll> > gp[n+2];
	vector<ll> val(n+2,0);
	adj= vector< vector<ll> > (n+2);
	for(int i=0;i<n-1;i++){
		ll x,y,w;
		cin>>x>>y>>w;
		gp[x].pb({y,w});	gp[y].pb({x,w});
		adj[x].pb(y);	adj[y].pb(x);
	}
	DFS(r,-1,gp,val,0);
	preprocess(r,n+2);
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll u=lca(x,y);
		ll Ans=val[x]+val[y]-2*val[u];
		cout<<Ans<<endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    cin>>t;                     // DON'T FORGET IT. ^^^  
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}
