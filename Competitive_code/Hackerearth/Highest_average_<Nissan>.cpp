/*
Link:https:https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/highest-average-64bdd761/
Learning:https://www.geeksforgeeks.org/longest-subsequence-whose-average-is-less-than-k/
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n;
    cin>>n;
    long int a[n];
    for(long int i=0;i<n;i++)
      cin>>a[i];

    sort(a,a+n);
    long int sum=0;
    vector<long int > v;
    for(long int i=0;i<n;i++)
    {
        sum+=a[i];
        long int x=sum/(i+1);
        v.push_back(x+1);
    }
    long int q;
    cin>>q;
    long int x;
    for(long int i=0;i<q;i++){
        cin>>x;
        long int ans=upper_bound(v.begin(),v.end(),x)-v.begin();
        cout<<ans<<endl;
    }
    return 0;
}
