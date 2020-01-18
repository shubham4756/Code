/*
fastest way for finding nth term of fabonacci series Link(https://www.hackerearth.com/practice/notes/fast-doubling-method-to-find-nth-fibonacci-number/)
Link:https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/fibonacci-with-gcd-16/
best properties of fabonacci series is below line.....
GCD( F(A_L), F(A_{L+1}), F(A_{L+2}) ...... F(A_R) ) \% 10^9+7 equals F( GCD ( A_{L}, A_{L+1}, A_{L+2} ) ) % 10^9+7
*/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
long int a,b,c,d;
long int tree[500006]={};
long int arr[100005]={};

void fast_fib(long int n,long int ans[])
{
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
}
void crateseg(long int l,long int r,long int pos){
    if(l==r)
    {
        tree[pos]=arr[l];
        return ;
    }
    if(l>r)
        return ;
    long int mid=l+(r-l)/2;
    crateseg(l,mid,2*pos);
    crateseg(mid+1,r,2*pos+1);
    tree[pos]=__gcd(tree[2*pos],tree[2*pos+1]);
    return ;
}
long int query(long int l,long int r,long int pos,long int ql,long int qr){
    if(l>r || ql>r || qr<l)
        return 0;
    if(ql<=l && qr>=r)
    {
        return tree[pos]%MOD;
    }
    long int mid=l+(r-l)/2;
    long int x=query(l,mid,2*pos,ql,qr);
    long int y=query(mid+1,r,2*pos+1,ql,qr);
    //cout<<x<<" "<<y<<endl;
    return (__gcd(x,y))%MOD;

}
int main(){
    long int n,q,x;
    cin>>n>>q;
    long int ans[2];
    for(long int i=1;i<=n;i++)
    {
        cin>>x;
        arr[i]=x;

    }
    cout<<endl;
    crateseg(1,n,1);
    long int xx,yy;
    while(q--)
    {
        cin>>xx>>yy;
        long int res=query(1,n,1,xx,yy)%MOD;
        fast_fib(res,ans);
        cout<<ans[0]<<endl;
    }
    return 0;
}
