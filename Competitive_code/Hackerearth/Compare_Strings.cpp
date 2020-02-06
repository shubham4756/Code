/*
Link: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/compare-strings-1-1cb66e03/
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    long int aa=0,bb=0;
    for(long int i=0;i<n;i++)
    {
        if(a[i]=='1') aa+=i+1;
        if(b[i]=='1') bb+=i+1;
    }
    long int x;
    for(long int i=0;i<n;i++)
    {  cin>>x;
      if(b[x-1]=='0')
          bb+=x;
      if(bb<aa)
          cout<<"NO\n";
      else
          cout<<"YES\n";
    }
    return 0;
}
