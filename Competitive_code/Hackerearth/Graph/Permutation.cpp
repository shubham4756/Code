/*
Link:https:https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/t1-1-6064aa64/
learning Link:https://www.geeksforgeeks.org/minimum-number-of-prefix-reversals-to-sort-permutation-of-first-n-numbers/
*/

#include<bits/stdc++.h>
using namespace std;
long int findnumberofcount(long int a[],long int n){
    string st="",ans="";
    for(long int i=0;i<n;i++)
        st+=to_string(a[i]);
    sort(a,a+n);
    for(long int i=0;i<n;i++)
        ans+=to_string(a[i]);

    queue<pair<string,long int> > q;
    pair<string ,long int > pr;
    q.push(make_pair(st,0));
    if(st==ans)
        return 0;
    while(!q.empty()){
        pr=q.front();
        q.pop();
        string s;
        for(long int j=2;j<=n;j++)
        {    s=pr.first;
            reverse(s.begin(),s.begin()+j);
           // cout<<s<<endl;
            if(s==ans)
                return pr.second+1;
            q.push(make_pair(s,pr.second+1));
        }
    }
}
int main(){
    long int n;
    cin>>n;
    long int a[n];
    for(long int i=0;i<n;i++)
        cin>>a[i];
    long int ans=findnumberofcount(a,n);
    cout<<ans<<endl;
    return 0;
}
