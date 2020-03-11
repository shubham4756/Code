/*
Link:https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/marriage-problem/description/
*/

#include<bits/stdc++.h>
using namespace std;
long int arr[2000001];
long int size[2000001];
long int m[2000001];
long int w[2000001];
long int x,y,n;
void preprocess() {
    for (long int i = 1; i <= n; i++) {
        arr[i] = i;
        size[i] = 1;
        if (i <= x) {
            m[i] = 1;
            w[i] = 0;
        } else {
            m[i] = 0;
            w[i] = 1;
        }
    }
}
long int find(long int x) {
    while (x != arr[x])
        x = arr[x];
    return x;
}
void makeunion(long int u,long int v) {
    long int xptr = find(u);
    long int yptr = find(v);
    if (xptr == yptr)
        return;

    if (size[xptr] >= size[yptr]) {
        arr[yptr] = xptr;
        size[xptr] += size[yptr];
        m[xptr] += m[yptr];
        w[xptr] += w[yptr];
    } else {
        arr[xptr] = yptr;
        size[yptr] += size[xptr];
        m[yptr] += m[xptr];
        w[yptr] += w[xptr];
    }
}
int main() {
    cin >> x >> y;
    n = x + y;
    preprocess();
    long int q1;
    cin >> q1;
    while (q1--) {
        long int u, v;
        cin >> u >> v;
        makeunion(u, v);
    }
    cin >> q1;
    while (q1--) {
        long int u, v;
        cin >> u >> v;
        makeunion(u + x, v + x);
    }
    cin >> q1;
    while (q1--) {
        long int u, v;
        cin >> u >> v;
        makeunion(u, v + x);
    }
    long int ans = 0;
    for (long int i = 0; i <= n; i++) {
        if (arr[i] == i) {
            // cout<<i<<" "<<m[i]<<","<<w[i]<<endl;
            long int man = m[i];
            long int woman = y - w[i];
            ans += man * woman;
            // cout<<man*woman<<endl;
        }
    }
    cout << ans << endl;
    return 0;
}
