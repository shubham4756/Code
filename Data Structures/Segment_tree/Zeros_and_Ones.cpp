/*
Link:https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/k-th-bit-faae0e0d/
*/


#include<bits/stdc++.h>
using namespace std;
void buildsg(long int pos,long int l,long int r,long int tree[],long int a[]){
  if(l==r)
  {
    tree[pos]=a[l];
   // cout<<"set "<<a[l]<<endl;
    return ;
  }
  else
  {
  long int mid=(l+r)/2;
  buildsg(2*pos,l,mid,tree,a);
  buildsg(2*pos+1,mid+1,r,tree,a);
  tree[pos]=tree[2*pos]+tree[2*pos+1];
  }
}
void update(long int pos,long int l,long int r,long int idx,long int val,long int tree[],long int a[]){
  if(l==r)
  { //cout<<"now \n";
    a[idx]=val;
    tree[pos]=val;
    return ;
  }
  else{
  long int mid=(l+r)/2;
  if(l<=idx && idx<=mid)
  update(2*pos,l,mid,idx,val,tree,a);
  else
  update(2*pos+1,mid+1,r,idx,val,tree,a);
  tree[pos]=tree[2*pos]+tree[2*pos+1];}
}

long int query(long int pos,long int l,long int r,long int val,long int tree[])
{ //cout<<"in fun\n";
  if(l==r && val==1)
  {   //cout<<"here\n";
      return r;}

  long int mid=(l+r)/2;
  if(val>tree[2*pos])
  {  //cout<<"larg\n";
    val=val-tree[2*pos];
    query(2*pos+1,mid+1,r,val,tree);
  }
  else{
     // cout<<"small\n";
    query(2*pos,l,mid,val,tree);
  }
}
int main(){
  long int n,q;
  cin>>n>>q;
  long int a[n+1];
  for(long int i=1;i<=n;i++)
     a[i]=1;

  long int xx=4*n;
  long int tree[xx]={1};
  buildsg(1,1,n,tree,a);
   long int ty,x;
  for(long int i=0;i<q;i++)
  {
     cin>>ty>>x;
     if(ty==1){
       if(tree[1]<x)
       {
         cout<<"-1\n";
       }
       else{
         cout<<query(1,1,n,x,tree)<<endl;
       }
     }
     else{
       update(1,1,n,x,0,tree,a);
     }
  }
  return 0;
}
