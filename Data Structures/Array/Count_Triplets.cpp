/*
Link:https://www.hackerrank.com/challenges/count-triplets-1/problem
*/

//First my solution giving WA 2 out of 13 idk why

#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
void solve() {
    ll n,r;
    cin >> n>>r;
    ll a[n];
    map<ll,ll> mp;
    ll maxx=0;
    for (long int i = 0; i < n; i++) {
        cin >> a[i];
        maxx=max(maxx,a[i]);
        mp[a[i]]++;
    }
    long int ans=0;
    if(r==1){
        for(auto it=mp.begin();it!=mp.end();it++) {
            ll x=it->second;
            ans += x * (x - 1) * (x - 2) / 6;
        }
    } else {
        for (auto it=mp.begin();it!=mp.end();it++) {
            ll fi=it->first;
            if (mp.find(r * fi) != mp.end() && mp.find(r * r * fi) != mp.end())
                ans += mp[fi] * mp[fi * r] * mp[fi * r * r];
        }
    }
    cout<<ans<<endl;
}
int main() {
    long int t=1;
//    cin >> t;
    while (t--)
        solve();
}


//second solution by problem setter 

#include<bits/stdc++.h>
using namespace std;

map<long long,long long> l,r;

int main()
{
	long long n, k,ans=0 ;
	scanf("%lld%lld",&n,&k);
	long long a[n];
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)
		r[a[i]]++;
	for(int i=0;i<n;i++)
	{
		r[a[i]]--;
		if(a[i]%k==0)
		{
			ans+=l[a[i]/k]*r[a[i]*k];
		}
		l[a[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}
