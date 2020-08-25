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

const int N=100010;
vector<long > g[N];
long tak[N],aok[N];

void dfs1(long nd,long cnt){
    for(int i=0;i<g[nd].size();i++){
        long nex=g[nd][i];
        if(tak[nex]!=0)
            continue;
        tak[nex]=cnt+1;
        dfs1(nex,cnt+1);
    }
}

void dfs2(long nd,long cnt){
    for(int i=0;i<g[nd].size();i++){
        long nex=g[nd][i];
        if(aok[nex]!=0)
            continue;
        aok[nex]=cnt+1;
        dfs2(nex,cnt+1);
    }
}

void solve(){
    long n;
    cin>>n;
    long u,v;
    cin>>u>>v;
    for(int i=0;i<n-1;i++){
        long x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    tak[u]=1,aok[v]=1;
    dfs1(u,1);
    dfs2(v,1);
    long ans=0;
    for(int i=1;i<=n;i++){
        if(aok[i]>tak[i])
            ans=max(ans,aok[i]);
    }
    cout<<ans-2<<endl;
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
