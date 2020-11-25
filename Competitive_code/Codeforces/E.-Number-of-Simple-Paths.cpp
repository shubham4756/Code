/*
Link: https://codeforces.com/contest/1454/problem/E
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

void solve(){
    ll n;
    cin>>n;
    vector< set<ll> >  gp(n);
    for(ll i=0;i<n;i++) {
        ll x,y;
        cin>>x>>y; x--, y--;
        gp[x].insert(y);
        gp[y].insert(x);
    }
    queue < ll > q;
    for(ll i=0;i<n;i++) {
        if(gp[i].size()==1) 
            q.push(i);
    }
    vector<ll> val(n,1);
    while(!q.empty()) {
        ll nd=q.front();
        q.pop();
        ll v=*gp[nd].begin();
        val[v]+=val[nd];
        val[nd]=0;
        gp[nd].clear();
        gp[v].erase(nd);
        if(gp[v].size()==1)
            q.push(v);
    }
    ll ANS=0;
    for(ll i=0;i<n;i++) {
        ANS+= ((val[i])*(val[i]-1))/2;
        ANS+= (val[i]*(n-val[i]));
    }
    cout<<ANS<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    cin>>t;                     // DON'T FORGET IT. ^^^ 
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}
