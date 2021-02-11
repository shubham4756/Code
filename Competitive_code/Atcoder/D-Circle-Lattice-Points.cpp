/*
Link: https://atcoder.jp/contests/abc191/tasks/abc191_d
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

long double x,y,r,k,a,b,eps=1e-12;
ll ans=0;
int main(){
	cin>>x>>y>>r;
	x+=200010,y+=200010;
	for(ll i=ceil(x-r-eps);i<=floor(x+r+eps);i++){
		k=sqrt(r*r-(x-i)*(x-i));
		a=ceil(y-k),b=floor(y+k);
		ans+=(ll)b-(ll)a+1;
	}
	cout<<ans;
	return 0;
}
