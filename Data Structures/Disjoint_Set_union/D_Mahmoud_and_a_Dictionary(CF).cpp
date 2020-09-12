/*
Link:https://codeforces.com/contest/766/problem/D
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

int n,q1,q2,Xor[N];
map< string , int > mp;
pair< int , int > A[N];
vector< pair < int , int > > v[N];
vector< pair < pair < int , int > ,pair< int , int > > > sub;
bool valid[N],vis[N];

int RT_find(int x){
	if(x==A[x].first)
		return A[x].first;
	else 
		return A[x].first=RT_find(A[x].first);
}

bool MK_union(int x,int y){
	x=RT_find(x);
	y=RT_find(y);
	if(x==y)
		return false;
	if(A[x].second<A[y].second){
		A[x].first=y;
	} else if(A[x].second>A[y].second){
		A[y].first=x;
	} else{
		A[x].first=y;
		A[x].second++;
	}
	return 1;
}

void dfs(int nd , int preNd , int X){
	Xor[nd]=X;
	vis[nd]=true;
	for(int i=0; i<v[nd].size();i++){
		if(v[nd][i].first!=preNd){
			dfs(v[nd][i].first,nd,X^v[nd][i].second);
		}
	}
}

void solve(){
	for(int i=0;i<n;i++){
		if(!vis[i])
			dfs(i,-1,0);
	}
	for(int i=0;i<sub.size();i++){
		int x=sub[i].first.first, y=sub[i].first.second , id=sub[i].second.first, ty=sub[i].second.second;
		if(Xor[x]^Xor[y]==ty){
			valid[id]=true;
		} else {
			valid[id]=false;
		}
	}
}

int main() {
	cin>>n>>q1>>q2;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		mp[s] = i;
		A[i]={i,0};
	}

	for(int i=0;i<q1;i++){
		int ty;
		string a,b;
		cin >> ty >> a >> b;
		int x = mp[a] , y = mp[b];
		if(MK_union(x,y)){
			v[x].pb({y,ty-1});
			v[y].pb({x,ty-1});
			valid[i]=true;
		} else {
			sub.pb({{x,y},{i,ty-1}});
		}
	}

	solve();

	for(int i=0;i<q1;i++){
		if(valid[i]){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}

	for(int i=0;i<q2;i++){
		string a,b;
		cin >> a >> b;
		int x = mp[a] , y = mp[b];
		if(RT_find(x)!=RT_find(y)){
			cout<<"3\n";
		} else if(Xor[x]^Xor[y]) {
			cout<<"2\n";
		} else {
			cout<<"1\n";
		}
	}
	return 0;
}
