/*
Link:https://www.hackerearth.com/practice/algorithms/sorting/radix-sort/practice-problems/algorithm/monk-and-sorting-algorithm/
*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lln;
void redixxsort(lln a[],long int n,long int ith){
    long int feq[100000]={0};
    long int ans[n];
    for(long int i=0;i<n;i++)
    {    long int tp=a[i]%(lln)pow(10,5*ith)-a[i]%(lln)pow(10,5*ith-5);
       tp/=pow(10,5*ith-5);
       // cout<<tp<<" "<<<<endl;
        feq[tp]++;
    }
    for(long int i=1;i<100000;i++)
        feq[i]+=feq[i-1];

     //cout<<"here\n";
    for(long int i=n-1;i>=0;i--){
        long int tp=a[i]%(lln)pow(10,5*ith)-a[i]%(lln)pow(10,5*ith-5);
        tp/=pow(10,5*ith-5);
        ans[feq[tp]-1]=a[i];
        feq[tp]--;
    }
    for(long int i=0;i<n;i++)
        a[i]=ans[i];
}
void fun(lln a[],long int n,lln maxx){
    long int i=1;
    while(maxx){
        //cout<<maxx<<endl;
        redixxsort(a,n,i);
        i++;
        maxx/=100000;
        for(long int j=0;j<n;j++)
            cout<<a[j]<<" ";
        cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n;
    cin>>n;
    lln a[n],maxx=0;
    for(long int i=0;i<n;i++) {
        cin >> a[i];
        maxx=max(maxx,a[i]);
    }
    fun(a,n,maxx);
}
