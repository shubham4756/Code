/*
Link:https://www.spoj.com/problems/KQUERYO/
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN=30010;
int a[MAXN];
vector<int> segTree[MAXN*4];
void seg_build(int idx,int l,int r) {
    if(l>r)
        return ;
    if (l == r) {
        segTree[idx].push_back(a[l]);
        return;
    }
    //cout<<l<<" "<<r<<endl;
    int mid = (l + r) / 2;
    seg_build(2 * idx, l, mid);
    seg_build(2 * idx + 1, mid + 1, r);
    segTree[idx].resize(segTree[2 * idx].size() + segTree[2 * idx + 1].size());
    merge(segTree[2 * idx].begin(), segTree[2 * idx].end(), segTree[2 * idx + 1].begin(), segTree[2 * idx + 1].end(),
          segTree[idx].begin());
}
int seg_query(int idx,int lo,int hi,int ql,int qr,int qk) {
    if (lo > qr || hi < ql)
        return 0;
 //   cout << lo << " -- " << hi << endl;
    if (lo >= ql && hi <= qr) {
        return segTree[idx].size() -
               (upper_bound(segTree[idx].begin(), segTree[idx].end(), qk) - segTree[idx].begin());
    }
    int mid = (lo + hi) / 2;
    return seg_query(2 * idx, lo, mid, ql, qr, qk) + seg_query(2 * idx + 1, mid + 1, hi, ql, qr, qk);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    seg_build(1,1,n);
    long int q;
    cin>>q;
    long int ql,qr,qk,preAns=0;
    while(q--){
        cin>>ql>>qr>>qk;
        ql=ql^preAns; qr=qr^preAns; qk=qk^preAns;
        preAns=seg_query(1,1,n,ql,qr,qk);
        cout<<preAns<<endl;
    }
}
