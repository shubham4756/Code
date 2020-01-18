/*
Link:https://www.codechef.com/problems/FLIPCOIN/
*/




//Segment tree implementation wid lazy propogation -
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
bool lazy[1000005];
int seg_tree[1000005]={0};
//To build tree wid nodes=0 tail
void build_tree(int seg_tree[],int node,int a,int b)
{	if(a>b) return ;
	if(a==b){ seg_tree[node]=0; return ;}
	build_tree(seg_tree, 2*node, a, (a+b)/2);
	build_tree(seg_tree, 2*node+1, (a+b)/2+1, b); 
	seg_tree[node] = seg_tree[2*node] + seg_tree[2*node+1];
	return ;
}
void update_tree(int seg_tree[],int node,int a,int b,int start,int end) //Range (start,end) to update
{	if(a>b)	return ;
	if(lazy[node]==1)
	{	seg_tree[node] = (b-a+1) - seg_tree[node]; //new count of no. f ones=total node under(a,b)range - prev ones
		if(a!=b)							       //not leaf node
		{	lazy[2*node] = !lazy[2*node];          //to pass the update flag to children
			lazy[2*node+1] = !lazy[2*node+1];
		}
		lazy[node] = 0; 
	}
	//Current segment not in range
	if(b<start||a>end)                             // a b start end || start end a b
	{	return ;
	}
	//Current segment fully in range	          
	if(a>=start && b<=end)                        // start a b end
	{	seg_tree[node] = (b-a+1) - seg_tree[node];
		if(a!=b)
		{	lazy[2*node] = !lazy[2*node];        //to pass the update flag to children
			lazy[2*node+1] = !lazy[2*node+1];	
		}
		return ;
	}
	update_tree(seg_tree,2*node,a,(a+b)/2,start,end);
	update_tree(seg_tree,2*node+1,(a+b)/2+1,b,start,end);
	seg_tree[node] = seg_tree[2*node] + seg_tree[2*node+1];
	return;
}
int query_tree(int seg_tree[],int node,int a,int b,int start,int end)
{	int ans;
	if(a>b||b<start||a>end)	return 0;
	if(lazy[node]==1)
	{	seg_tree[node] = (b-a+1) - seg_tree[node];
		if(a!=b)
		{	lazy[2*node]=!lazy[2*node];
			lazy[2*node+1]=!lazy[2*node+1];
		}
		lazy[node]=0;
	}
	if(a>=start&&b<=end)
		return seg_tree[node];
	ans = query_tree(seg_tree,2*node,a,(a+b)/2,start,end) + query_tree(seg_tree,2*node+1,(a+b)/2+1,b,start,end);	
	return ans;
}
int main()
{
	int n,q,x,a,b,ans;
	scanf("%d%d",&n,&q);
	//int max=(ceil(log2(n)));
	//int memory=2*(int)pow(2,max)-1;
	//int seg_tree[memory+10];
	build_tree(seg_tree,1,0,n-1);
	memset(lazy,0,sizeof(lazy));
	while(q--)
	{
		scanf("%d%d%d",&x,&a,&b);
		if(x==0)
			update_tree(seg_tree,1,0,n-1,a,b);
		else if(x==1)
		{	ans=query_tree(seg_tree,1,0,n-1,a,b);
			printf("%d\n",ans);
		}
	}
	return 0;
}
