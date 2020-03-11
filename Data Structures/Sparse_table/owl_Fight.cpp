/*
Link: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/
Link: https://www.youtube.com/watch?v=wq6TCikSzpk&list=PL2q4fbVm1Ik4JdzE2Bv_UUGBz0TXEIrai&index=7
*/

#include<bits/stdc++.h>
using namespace std;
long int n,m;
int a[100005];
int size[100005];
void preprocess() {
    for (int i = 0; i <= n; i++) {
        a[i] = i;
        size[i] = 1;
    }
}
long int find(long int x) {
    if (x != a[x])
        a[x] = find(a[x]);
    return a[x];
}
void makeunion(long int x,long int y) {
    long int xpre = find(x);
    long int ypre = find(y);
    if (xpre == ypre)
        return;
    if (size[xpre] >= size[ypre]) {
        a[ypre] = a[xpre];
        size[ypre] += size[xpre];
    } else {
        a[xpre] = a[ypre];
        size[xpre] += size[ypre];
    }
}
int main() {
    cin >> n >> m;
    preprocess();
    long int u, v;
    while (m--) {
        cin >> u >> v;
        makeunion(u, v);
    }
    vector<long int> vec[n + 1];
    for (long int i = 1; i <= n; i++) {
        long int root = find(i);
        vec[root].push_back(i);
    }
    int maxx[n + 1];
    for (long int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end());
        if (vec[i].size()) {
            maxx[i] = vec[i][vec[i].size() - 1];
        }
    }
    long int q;
    cin >> q;
    while (q--) {
        long int x, y;
        cin >> x >> y;
        long int xx = find(x);
        long int yy = find(y);
        if (maxx[xx] > maxx[yy]) cout << x << endl;
        else if (maxx[xx] < maxx[yy]) cout << y << endl;
        else cout << "TIE\n";
    }
    return 0;
}
