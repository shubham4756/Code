/*
Link: https://www.codechef.com/INDC2021/problems/ROBRPLAN
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
		int x,y;cin>>x>>y;
		int a,b;cin>>a>>b;
		int n,m;cin>>n>>m;
		if(n>m)swap(n,m),swap(a,b);
		int ans=0;
		for(int i=0;i<=a;i++){
			int w1=n*i;
			if(w1>x)break;
			int rem=x-w1;
			int can_take=min(b,rem/m);
			int rem_2=b-can_take;
			int val=i+can_take;
			int can_take1=min(a-i,y/n);
			int w_rem2=y-can_take1*n;
			int can_take_2=min(rem_2,w_rem2/m);
			ans = max(ans,val+can_take1+can_take_2);
		}	
		cout<<ans<<endl;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}
