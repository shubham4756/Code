/*
Link:https://atcoder.jp/contests/abc153/tasks/abc153_f
*/

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
const int MOD=1e9 + 7;
const int N=1000100;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){  
                                                        for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve(){
    long n,d,a;
    cin>>n>>d>>a;
    vector< pair<long,long> > v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    vector<long>  x(n),h(n),cnt(n+1,0);
    for(int i=0;i<n;i++){
        x[i]=v[i].first; h[i]=v[i].second;
    }
    ll ans=0,id=0;
    for(int i=0;i<n;i++){
        if(i)
            cnt[i]+=cnt[i-1];
        h[i]-=cnt[i]*a;
        if(h[i]<=0)
            continue;
        long num=(h[i]+a-1)/a;
        ans+=num;
        cnt[i+1]+=num;
        while(id<n && x[id]-x[i]<=2*d)
            id++;
        cnt[id]-=num;
    }
    cout<<ans<<endl;
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
