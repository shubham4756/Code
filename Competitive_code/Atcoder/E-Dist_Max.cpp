/*
Link: https://atcoder.jp/contests/abc178/tasks/abc178_e
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
	long n;
	cin>>n;
	ll Minn1=LLONG_MAX,Maxx1=-LLONG_MAX;
	ll Minn2=LLONG_MAX,Maxx2=-LLONG_MAX;
	for(long i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		Minn1=min(Minn1,x+y);
		Maxx1=max(Maxx1,x+y);
		Minn2=min(Minn2,x-y);
		Maxx2=max(Maxx2,x-y);
	}
	cout<<max( abs(Maxx1 - Minn1) , abs(Maxx2 - Minn2 ) )<<endl;
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
