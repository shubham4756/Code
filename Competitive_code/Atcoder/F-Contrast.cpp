/*
Link : https://atcoder.jp/contests/abc178/tasks/abc178_f
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
const int N=2*100005;

void solve(){
	long n;
	cin>>n;
	vector<long> a(n+1),b(n+1),c(n+1),cntA(n+1,0),cntB(n+1,0);
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>b[i];
	for(int i=1;i<=n;i++)	cntA[a[i]]=i;
	for(int i=n;i>=1;i--)	cntB[b[i]]=i;
	long ans=0;
	for(int i=1;i<=n;i++){
		if(cntA[i] && cntB[i])
			ans=max(ans,cntA[i]-cntB[i]+1);
	}
	for(int i=1;i<=n;i++)
		c[(i+ans)>n ? i+ans-n : i+ans ]=b[i];
	
	bool ok=true;
	for(int i=1;i<=n;i++){
		if(a[i]==c[i])
			ok=false;
	}
	if(!ok){
		cout<<"No\n";
	} else {
		cout<<"Yes\n";
		for(int i=1;i<=n;i++)
			cout<<c[i]<<" ";
	}
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
