/*
Link: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/analytically-stable-123d6381/description/
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int Md=1000000007;
void solve() {
	string s;
	cin>>s;
	ll n=s.size();
	ll pr[n][10];
	memset(pr,0,sizeof(pr));
	for(ll i=0;i<n;i++) {
		if(i!=0)
		for(ll j=0;j<10;j++)
			pr[i][j]+=pr[i-1][j];
		pr[i][s[i]-'0']++;
	}
	ll sf[n][10];
	memset(sf,0,sizeof(sf));
	for(ll i=n-1;i>=0;i--) {
		if(i!=n-1)
		for(ll j=0;j<10;j++)
			sf[i][j]+=sf[i+1][j];
		sf[i][s[i]-'0']++;
	}
	ll res=0;
	for(ll i=1;i<n-1;i++) {
		if(s[i]=='9')
			continue;
		ll c1= pr[i-1][s[i]-'0'];
		ll c2= sf[i+1][s[i]-'0'+1];
		if(c2!=0) {
			c2=(c2*(c2-1)/2)%Md;
			res = (res + (c1*c2)%Md)%Md;
		}
	}
	cout<<res <<endl;
}
int main() {
	ll t;
	cin>>t;
	while(t--)
		solve();
    return 0;
}
