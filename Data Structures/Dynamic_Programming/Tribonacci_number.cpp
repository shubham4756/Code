/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/coin-toss/
Learning:https://www.geeksforgeeks.org/tribonacci-numbers/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
/*==========================================FUNCTIONS====================================*/
void multiply(long int t[3][3],long int m[3][3]){
    long int mul[3][3];
    for(long int i=0;i<3;i++){
        for(long int j=0;j<3;j++){
            mul[i][j]=0;
            for(long int k=0;k<3;k++){
                mul[i][j]=(mul[i][j]+(t[i][k]%Mod*m[k][j]%Mod)%Mod)%Mod;
            }
        }
    }
    for(long int i=0;i<3;i++){
        for(long int j=0;j<3;j++)
            t[i][j]=mul[i][j];
    }
}
void power(long int t[3][3],long int n){
     if(n==0 || n==1)
         return ;
     long int m[3][3]={{1,1,1},{1,0,0},{0,1,0}};
     power(t,n/2);
     multiply(t,t);
     if(n%2)
         multiply(t,m);
}
long int tribonaci(long int n){
    long int t[3][3]={{1,1,1},{1,0,0},{0,1,0}};
    if(n==0 || n==1)
        return 0;
    else
        power(t,n-2);

    return t[0][0];
}
/*==========================================MAIN====================================*/
int main() {
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
     long int t;
     cin>>t;
     while(t--){
         long int n;
         cin>>n;
         cout<<tribonaci(n+3)<<endl;
     }
    return 0;
}
