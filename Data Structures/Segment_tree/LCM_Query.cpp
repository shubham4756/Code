/*
Link:https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-15-august/challenges/lcm-query/problem
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
#define inf (int) (1e18)

const int MOD=1000000007;
const int N=100005+100;
int n,q;
struct SegTree {
    int Tree[N<<2];
    SegTree() {
        memset(Tree, 0, sizeof(Tree));
    }
    void update(int id, int val, int node = 1, int start = 0, int end = n) {
        if (start == end) {
            return void(Tree[node] = val);;
        }
        int mid = start + end >> 1;
        if (id <= mid)
            update(id, val, node<<1, start, mid);
        else
            update(id, val, node<<1|1, mid + 1, end);
        Tree[node] = max(Tree[node<<1], Tree[node<<1|1]);
    }
    int query(int l, int r, int node = 1, int start = 0, int end = n) {
        if (l > end || r < start)
            return 0;
        if (start >= l && end <= r) {
            return Tree[node];
        }
        int mid = start + end >> 1;
        return max(query(l, r,node<<1, start, mid), query(l, r, node<<1|1 , mid + 1, end));
    }
}seg[180];
long long pwer(long long a, int n) {
    if(n == 0)return 1;
    if(n == 1)return a;
    int p = pwer(a,n/2);
    p = p * p % MOD;
    if(n&1)p = p * a % MOD;
    return p;
}

void solve() {
    bool p[1010];
    memset(p,false,sizeof(p));
    for (int i = 2; i < 1010; i++) {
        if (p[i])
            continue;
        for (int j = 2; i * j < 1010; j++) {
            p[i * j] = true;
        }
    }
    vector<int> primes;
    for (int i = 2; i < 1000; i++) {
        if (!p[i])
            primes.pb(i);
    }

    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; ++i){
        int a;
        scanf("%d",&a);
        for(int j = 0; j < primes.size(); ++j){
            int cnt = 0;
            while(a && a%primes[j] == 0)a/=primes[j],cnt++;
            if(cnt){
                seg[j].update(i,cnt);
            }
        }
    }
    vector<int> ans(primes.size());

    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        long long res = 1;
        for(int j = 0; j < primes.size(); ++j)ans[j] = 0;
        for(int j = 0; j < primes.size(); ++j){
            int pw = seg[j].query(l-1,r-1);
            ans[j] = max(ans[j],pw);
        }
        for(int j = 0; j < primes.size(); ++j){
            if(ans[j])res = res * pwer(primes[j],ans[j]) % MOD;
        }
        printf("%lld\n",res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
