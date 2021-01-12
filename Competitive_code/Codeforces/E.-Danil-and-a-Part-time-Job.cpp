/*
Link: https://codeforces.com/contest/877/problem/E
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+1;
int n,timer;
int st[N],en[N],a[N],c[N];
vector <int> g[N];
int tree[4*N],lazy[4*N];

void build(int node,int l,int r) {
    if (l == r) {
        tree[node] = c[a[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(int node,int l,int r,int ql,int qr) {
    if (lazy[node]) {
        if (lazy[node] & 1)
            tree[node] = (r - l + 1) - tree[node];
        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (l > r || ql > qr || l > qr || r < ql)
        return;
    if (l >= ql && r <= qr) {
        tree[node] = (r - l + 1) - tree[node];
        if (l != r) {
            lazy[2 * node] += 1;
            lazy[2 * node + 1] += 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(2 * node, l, mid, ql, qr);
    update(2 * node + 1, mid + 1, r, ql, qr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int node,int l,int r,int ql,int qr) {
    if (lazy[node]) {
        if (lazy[node] & 1)
            tree[node] = (r - l + 1) - tree[node];
        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (l > r || ql > qr || l > qr || r < ql)
        return 0;
    if (l >= ql && r <= qr)
        return tree[node];
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}
void dfs(int v) {
    st[v] = ++timer;
    a[timer] = v;
    for (auto u:g[v])
        dfs(u);
    en[v] = timer;
}
int32_t main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1);
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        string s;
        int v;
        cin >> s >> v;
        if (s == "get")
            cout << query(1, 1, n, st[v], en[v]) << "\n";
        else
            update(1, 1, n, st[v], en[v]);
    }
    return 0;
}
