/*
Link:https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/password-cracker-de8d54f1/
*/

#include<bits/stdc++.h>
using namespace std;
int bit[10][1000001]={0};
int len=0;
void update(int idx,char x,int val){
    for(;idx<=len;idx+=((idx)&(-idx)))
        bit[x-'0'][idx]+=val;
}
long int  finddigit(long int idx,long int i){
    long int sum=0;
    for(;idx>0;idx-=((idx)&(-idx)))
        sum+=bit[i][idx];
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;
    len=a.size();
    for(int i=0;i<len;i++)
    {
        update(i+1,a[i],1);
    }
    long int q;
    cin>>q;
    while(q--){
        long int ty;
        cin>>ty;
        if(ty==1){
            long int x;
            char y;
            cin>>x>>y;
            x--;
            update(x+1,a[x],-1);
            a[x]=y;
            update(x+1,a[x],1);
        }
        else if(ty==2) {
            long int x, y, idx;
            cin >> x >> y >> idx;
            long int ans[10] = {0};
            long int sum=0;
            for (int i = 0; i < 10; i++)
            {
                ans[i] = finddigit(y, i) - finddigit(x - 1, i);
                sum+=ans[i]*i;
            }
            long int d=sum/9;
                ans[9*(d+1)-sum]++;
            int i=9;
            while(idx>0 && i>=0){
                idx-=ans[i];
                i--;
            }
            cout<<i+1<<endl;
        }
    }
    return 0;
}
