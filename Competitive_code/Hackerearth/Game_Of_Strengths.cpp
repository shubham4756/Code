/*
Que. Link: https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/game-of-strengths-4/
gfg Link:https://www.geeksforgeeks.org/sum-absolute-differences-pairs-given-array/
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
    long int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        long int a[n];
        for(long int i=0;i<n;i++)
              cin>>a[i];

        sort(a,a+n);
        long int ans=0;
        for(long int i=0;i<n;i++)
            ans=(ans+(i*a[i]-(n-1-i)*a[i]))%mod;
        cout<<(ans*a[n-1])%mod<<endl;
    }
    return 0;
}
