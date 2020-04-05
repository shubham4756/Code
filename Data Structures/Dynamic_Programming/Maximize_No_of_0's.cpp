/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/number-of-rs-1/
Learning:
https://www.geeksforgeeks.org/maximize-number-0s-flipping-subarray/
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
/*=============================================FUNCTIONS======================================*/
void solve(){
    string s;
    cin>>s;
    long int n=s.size(),rr=0;
    long int a[n];
    for(long int i=0;i<n;i++){
        if(s[i]=='K')
            a[i]=1;
        else{
            rr++;
            a[i]=0;
        }
    }
    if(rr==n){              //here given that at least one move happning
        cout<<n-1<<endl;
        return ;
    }
    long int zero=0,currmax=0,maxzero=0;
    for(long int i=0;i<n;i++){
        if(a[i]==0)
            zero++;

        long int val=(a[i]==1)?1:-1;

        currmax=max(val,currmax+val);
        maxzero=max(maxzero,currmax);
    }
    maxzero=max((long)0,maxzero);
    cout<<zero+maxzero<<endl;
}
/*==============================================MAIN============================================*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
