//Link:https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/distinct-integers-in-range-66eca44b/
#include<bits/stdc++.h>
using namespace std;
const int mx=100001; 
long int a[mx],b[mx];
bitset<5001>  setA[4*mx];  //it's required to be globel other wise it give sagment error
bitset<5001>  setB[4*mx];
void cratesegT(long int l,long int r,long int pos){
    if(l==r)
    {   setA[pos].set(a[l]);
        setB[pos].set(b[l]);
        return ;
    }
    else{
        long int mid=(l+r)/2;
        cratesegT(l,mid,2*pos+1);
        cratesegT(mid+1,r,2*pos+2);
        setA[pos]=(setA[2*pos+1]|setA[2*pos+2]);
        setB[pos]=(setB[2*pos+1]|setB[2*pos+2]);
    }
}

bitset<5001> findfromtree(long int l,long int r,long int ql,long int qr,long int pos){

    if(ql>r || qr<l)
        return 0;

    if(ql<=l && r<=qr)
    {
        return setA[pos];
    }
    else{
        long int mid=(l+r)/2;
        return (findfromtree(l,mid,ql,qr,2*pos+1)|findfromtree(mid+1,r,ql,qr,2*pos+2));
    }
}

bitset<5001> findfromtree1(long int l,long int r,long int ql,long int qr,long int pos){

    if(ql>r || qr<l)
        return 0;

    if(ql<=l && r<=qr)
    {
        return setB[pos];
    }
    else{
        long int mid=(l+r)/2;
        return (findfromtree1(l,mid,ql,qr,2*pos+1)|findfromtree1(mid+1,r,ql,qr,2*pos+2));
    }
}
int main(){
    long int  n;
    cin>>n;
    for(long int i=0;i<n;i++)
        cin>>a[i];
    for(long int i=0;i<n;i++)
        cin>>b[i];

    cratesegT(0,n-1,0);
    long int q,x,y,c,d;
    cin>>q;
    for(long int i=0;i<q;i++)
    {
        cin>>x>>y>>c>>d;
        x--; y--; c--; d--;
        bitset<5001> temp;
        bitset<5001> tp;
        temp=findfromtree(0,n-1,x,y,0);
        tp=findfromtree1(0,n-1,c,d,0);
        tp=(temp|tp);
        cout<<tp.count()<<endl;
    }
    return 0;
}
