/*
Link: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/string-query-22/
*/

#include<bits/stdc++.h>
using namespace std;
long int bit[26][200005]={0};
long int len=0;
void update(char x,long int idx,long int val){
    for(;idx<=len;idx+=((idx)&(-idx)))
        bit[x-'a'][idx]+=val;
}
int query(long int idx,char ch){
    int sum=0;
    for(;idx>0;idx-=((idx)&(-idx)))
        sum+=bit[ch-'a'][idx];
    return sum;
}
int binary(long int idx,char ch,string& s){
    long int l=1,r=len;
    long int mid;
    while(l<=r){
        mid=(l+r)/2;
        long int tp=query(mid,ch);
        if(tp==idx)
            break;
        else if(tp>idx)
            r=mid-1;
        else l=mid+1;
    }
    for(int i=mid-1;i>=0;i--){
        if(s[i]==ch)
            return i+1;
    }
    return -1;
}
int main(){
    string s;
    cin>>s;
    len=s.size();
    for(long int i=0;i<len;i++)
    {
        update(s[i],i+1,1);
    }
    long int q;
    cin>>q;
    while(q--){
        long int idx;
        char ch;
        cin>>idx>>ch;
        long int id=binary(idx,ch,s);
        update(ch,id,-1);
        s[id-1]='#';
    }
    for(long int i=0;i<len;i++) {
        if (s[i] != '#')
            cout << s[i];
    }
    return 0;
}
