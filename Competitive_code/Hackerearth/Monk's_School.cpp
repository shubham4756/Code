/*
Link:https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/monks-school-4/
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n,m;
    cin>>n>>m;
    string str;
    for(long int i=0;i<n;i++)
        cin>>str;
    map<string ,map<long int,string >  > mp;
    string x,y;
    long int num;
    for(long int i=0;i<m;i++)
    {
        cin>>x>>y>>num;
        mp[x][num]=y;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {   map<long int,string > vv=it->second;
        cout<<it->first<<endl;
        for(auto itr=vv.begin();itr!=vv.end();itr++)
            cout<<itr->second<<" "<<itr->first<<endl;
    }
    return 0;
}
