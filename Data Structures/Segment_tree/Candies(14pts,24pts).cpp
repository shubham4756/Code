/*
Link:https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll w[10000001],wo[10000001];
void buildSeg(long int idx,long int l,long int r,long int a[]) {
    if (l == r) {
        if (l % 2 == 0) {
            w[idx] = (-l * a[l]);
            wo[idx] = (-a[l]);
        } else {
            w[idx] = (l * a[l]);
            wo[idx] = (a[l]);
        }
        return;
    }
    ll mid = (l + r) / 2;
    buildSeg(2 * idx, l, mid, a);
    buildSeg(2 * idx + 1, mid + 1, r, a);
    w[idx] = w[2 * idx] + w[2 * idx + 1];
    wo[idx] = wo[2 * idx] + wo[2 * idx + 1];
    return;
}
void updateSeg(long int idx,long int l,long int r,long int node,long int val) {
    if (l == r) {
        if (l % 2 == 0) {
            w[idx] = (-l * val);
            wo[idx] = (-val);
        } else {
            w[idx] = (l * val);
            wo[idx] = (val);
        }
        return;
    }
    ll mid = (l + r) / 2;
    if (node >= l && node <= mid)
        updateSeg(2 * idx, l, mid, node, val);
    else
        updateSeg(2 * idx + 1, mid + 1, r, node, val);
    w[idx] = w[2 * idx] + w[2 * idx + 1];
    wo[idx] = wo[2 * idx] + wo[2 * idx + 1];
    return;
}
ll querySeg(long int idx,long int l,long int r,long int reql,long int reqr,bool wf) {
    if (reqr < l || reql > r)
        return 0;
    //cout << l << " " << r << " " << reql << " " << reqr << endl;
    if (reql <= l && reqr >= r) {
        if (wf) return w[idx];
        else return wo[idx];
    }
    ll mid = (l + r) / 2;
    ll p1 = querySeg(2 * idx, l, mid, reql, reqr, wf);
    ll p2 = querySeg(2 * idx + 1, mid + 1, r, reql, reqr, wf);
    return (p1 + p2);
}
void solve() {
    long int n, q;
    cin >> n >> q;
    ll ans = 0;
    long int a[n + 1];
    for (long int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    buildSeg(1, 1, n, a);
    while (q--) {
        char c;
        long int l, r;
        cin >> c >> l >> r;
        if (c == 'U') {
            updateSeg(1, 1, n, l, r);
            cout << endl;
        } else {
            ll s = querySeg(1, 1, n, l, r, true);
//            cout<<s<<" "<<querySeg(1, 1, n, l, r, false)<<endl;
            s = s - (l - 1) * querySeg(1, 1, n, l, r, false);
            if (l % 2 == 0)
                s = -s;
//            cout<<s<<endl;
            ans += s;
        }
    }
    cout << ans;
}
int main(){
    long int t;
    cin>>t;
    for(long int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl;
    }
    return 0;
}
