/*
Link: https://codeforces.com/contest/909/problem/E
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

void solve(){
	ll n,m;
	cin>>n>>m;
	ll bit[n],in[n]={0};
	vector<ll> v[n];
	for(ll i=0;i<n;i++)
		cin>>bit[i];
	for(ll i=0;i<m;i++) {
		ll x,y; cin>>x>>y;
		v[x].pb(y);
		in[y]++;
	}
	queue<ll> q[2];
	ll res=0;
	for(ll i=0;i<n;i++) {
		if(!in[i])
			q[bit[i]].push(i);
	}
	while(1) {
		while(!q[0].empty()) {
			ll nd=q[0].front(); q[0].pop();
			for(auto y:v[nd]) {
				in[y]--;
				if(!in[y])
					q[bit[y]].push(y);
			}
		}
		if(q[1].empty())
			break;
		res++;
		while(!q[1].empty()) {
			ll nd=q[1].front(); q[1].pop();
			for(auto y:v[nd]) {
				in[y]--;
				if(!in[y])
					q[bit[y]].push(y);
			}
		}
	}
	cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    // cin>>t;                     // DON'T FORGET IT. ^^^ 
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}
