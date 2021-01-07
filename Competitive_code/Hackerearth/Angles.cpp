/*
Link: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/angles-2/description/?layout=old
*/

// First Solution

#include <bits/stdc++.h>
using namespace std;
int main() {
    int k , n, tem1;
    cin >> n >> k;
    int gcd = 360;
    for(int i = 0; i < n; i++){
        cin >> tem1;
        gcd = __gcd(gcd, tem1);
    }
    for(int i = 0; i < k; i++){
        cin >> tem1;
        if(tem1 % gcd == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


// Second Solution

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int Md=1000000007;
const int N=10005;
void solve() {
	ll n,k;
	cin>>n>>k;
	ll an[n];
	bool ck[N]; 
	memset(ck,false,sizeof(ck));
	queue<ll> q;
	for(ll i=0;i<n;i++) {
		cin>>an[i];
		ck[an[i]]=true;
		q.push(an[i]);
	}
	bool res[370];
	memset(res,false,sizeof(res));
	while(!q.empty()) {
		ll tp=q.front();
		q.pop();
		for(ll j=0;j<n;j++) {
			if(tp-an[j]>=0 && ck[tp-an[j]]==false) {
				ck[tp-an[j]]=true;
				q.push(tp-an[j]);
			}
			if(tp+an[j]<N && ck[tp+an[j]]==false) {
				q.push(tp+an[j]);
				ck[tp+an[j]]=true;
			}
		}
	}
	for(ll i=0;i<N;i++) {
		if(ck[i]) {
			res[i%360]=true;
		}
	}
	while(k--) {
		ll x;
		cin>>x;
		if(res[x]) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
int main() {
	ll t=1;
	// cin>>t;
	while(t--)
		solve();
    return 0;
}
