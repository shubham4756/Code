/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
const int  MOD=1000000007;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
const int N=1000010;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    cin>>a;
    ll c[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c[i][j];
        }
    }
    vector<pair<ll,ll> > maxRating(n,{-LLONG_MAX,-1}),maxRank(n,{LLONG_MAX,-1});
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            a[i]+=c[i][j];
            if(a[i]>maxRating[i].first){
                maxRating[i]={a[i],j};
            }
        }
        vector<pair<ll,ll> > temp;
        for(int i=0;i<n;i++){
            temp.pb({a[i],i});
        }
        sort(temp.begin(),temp.end(),greater<pair<long long int , long long int>>());
        int p=1;
        for(int i=0;i<n;i++){
            if(i!=0){
                if(temp[i-1].first!=temp[i].first) p=i+1;
            }
            if(maxRank[temp[i].second].first>p){
                maxRank[temp[i].second].first=p;
                maxRank[temp[i].second].second=j;
            }
        }
    }
    long ans=0;
    for(int i=0;i<n;i++){
        if(maxRank[i].second!=maxRating[i].second)
            ans++;
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
