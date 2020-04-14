/*
Link:https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/flipping-the-string-831bbbbe/
Learning:https://www.geeksforgeeks.org/longest-subarray-count-1s-one-count-0s/
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//const long MAXN=100;
typedef long long int ll;
void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<ll,ll> mp;
    ll sum=0,maxLen=0;
    for(ll i=0;i<n;i++){
		if(s[i]=='0')
		s[i]='1';
		else
		s[i]='0';
        
		sum+=s[i]=='0'?-1:1;
        if(sum==1)
            maxLen=i+1;
        else if(mp.find(sum)==mp.end())
            mp[sum]=i;

        if(mp.find(sum-1)!=mp.end()){
            maxLen=max(maxLen,i-mp[sum-1]);
        }
    }
	if(sum>=1)
	  maxLen=n;
    cout<<maxLen<<endl;
}
int main() {
//     long t;
//     cin>>t;
//     while(t--)
        solve();
    return 0;
}
