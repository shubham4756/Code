/*
Link:https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/teachers-dilemma-3/

Link:https://www.geeksforgeeks.org/disjoint-set-data-structures/
*/

#include<bits/stdc++.h>
using namespace std;
const  int M=1000000007;
long int n,m;
long int a[100005];
long int size[100005];
void preprocess() {
    for (long int i = 0; i <= n; i++) {
        a[i] = i;
        size[i] = 1;
    }
}
long int find(long int x) {
    while (a[x] != x) {
        x = a[x];
    }
    return x;
}
void unionnn(long int u,long int v) {
    long int xpre = find(u);
    long int ypre = find(v);
    if (xpre == ypre)
        return;
    if (size[xpre] >= size[ypre]) {
        a[ypre] = xpre;
        size[xpre] += size[ypre];
    } else {
        a[xpre] = ypre;
        size[ypre] += size[xpre];
    }
    //cout<<size[xpre]<<" "<<xpre<<" "<<size[ypre]<<" "<<ypre<<endl;
}
int main() {
    cin >> n >> m;
    preprocess();
    long int u, v;
    while (m--) {
        cin >> u >> v;
        unionnn(u, v);
    }
    long long int ans = 1;
    for (long int i = 1; i <= n; i++) {
        if (a[i] == i) {
            //  cout<<i<<" "<<size[i]<<endl;
            ans = ((ans % M) * (size[i] % M)) % M;
        }
    }
    cout << ans << endl;
}
