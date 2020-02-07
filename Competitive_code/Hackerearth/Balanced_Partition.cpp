/*
Link:https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/balanced-partition-818edecd/
*/



#include<bits/stdc++.h>
using namespace std;
int main(){
    long int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        long int x,y,h,s1=0,s2=0;
        map<long int ,long int > mp;
        for(int i=0;i<n;i++)
        {   cin>>x>>y>>h;
            mp[x-y]+=h;
            s1+=h; }
        bool flag=0;
        for(auto it:mp)
        {   if(s1-it.second==2*s2)
            {   flag=1;
                break; }
            s2+=it.second;
            if(s1/2==s2)
            {   flag=1;
                break; }
        }
        if(flag==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
