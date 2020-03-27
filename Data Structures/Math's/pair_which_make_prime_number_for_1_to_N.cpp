/*
Link:https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/war-begin/
Learning:https://www.geeksforgeeks.org/count-pairs-sum-prime-number-less-n/
-------->in Learning link only odd numbers sieves whose created so learn it it's very helpfull<---------
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 5000005
const long int Mod=100000007;
bool prime[MAXN];
long long int ans[MAXN];
void pre() {
    prime[0]=prime[1]=true;
    for (long int i = 2; i*i < MAXN; i++) {
        if(!prime[i])
            for (long int j = i * 2; j < MAXN; j += i)
                prime[j]=true;
    }
    prime[2]=true;
    long long int xx=0;
    for(long int i=0;i<MAXN;i++){
        if(!prime[i])
            xx=(xx+(i/2))%Mod;
        ans[i]=xx%Mod;
    }
}
int main() {
    pre();
    long int t;
    scanf("%ld",&t);
    while(t--){
        long int n;
        scanf("%ld",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
