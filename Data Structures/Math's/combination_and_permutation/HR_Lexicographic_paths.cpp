/*
Link:https://www.hackerrank.com/challenges/lexicographic-steps/problem
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
long int ncr(long int n,long int r){
    if(n==0 && r==0)
        return 0;
    long int res=1;
    if(r>n-r)
        r=n-r;

    for(long int i=0;i<r;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int main() {
    long int t;
    cin >> t;
    while (t--) {
        long int x,y,k;
        cin>>x>>y>>k;
        while(1){
            if(x==0 && y==0)
                break;
            else if(x==0){
                cout<<"V";
                y--;
            }
            else if(y==0){
                cout<<"H";
                x--;
            }
            else{
                if(ncr(x+y-1,x-1)>k){
                    x--;
                    cout<<"H";
                }
                else{
                    k=k-ncr(x+y-1,x-1);
                    y--;
                    cout<<"V";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
