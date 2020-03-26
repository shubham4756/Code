/*
Link:https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/coprcopr/
Learning:https://www.geeksforgeeks.org/queries-to-count-the-number-of-unordered-co-prime-pairs-from-1-to-n/
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000001
//bool prime[MAXN];
//long int NoPri[MAXN];
//void pre() {
//    prime[0]=true;
//    prime[1]=true;
//    for (long int i = 2; i * i < MAXN; i++) {
//        if (!prime[i]) {
//            for (long int j = i * i; j < MAXN; j += i)
//                prime[j] = true;
//        }
//    }
//    prime[4]=false;
//    NoPri[0]=0;
//    for(long int i=1;i<MAXN;i++) NoPri[i]=NoPri[i-1]+(!prime[i]);
//}
//long int euler(long int n) {
//    long int xx = 0, res = n;
//    for (long int i = 2; i * i <= n; i++) {
//        if (n % i == 0) {
//            while (n % i == 0)
//                n /= i;
//            res -= res / i;
//        }
//    }
//    if (n > 1)
//        res -= res / n;
//    return res;
//}
//long int numberofdiv(long int n) {
//    long int xx = 1;
//    for (long int i = 2; i * i <= n; i++) {
//        if (n % i == 0) {
//            if (n / i == i)
//                xx++;
//            else
//                xx += 2;
//        }
//    }
//    return xx;
//}
//bool isPrime(long int n) {
//    for (long int i = 2; i * i <= n; i++) {
//        if (n % i == 0)
//            return false;
//    }
//    return true;
//}
long long int phi[MAXN]={0},cnt[MAXN]={0};
void pre1() {
    for (long int i = 1; i < MAXN; i++)
        phi[i] = i;
    for (long int i = 2; i < MAXN; i++) {
        if (phi[i] == i) {
            phi[i] = i - 1;
            for (long int j = 2 * i; j < MAXN; j += i) {
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
    cnt[1]=1;
    for(long int i=2;i<MAXN;i++) cnt[i]=cnt[i-1]+phi[i];
}
int main() {
    pre1();
    long int t;
    scanf("%ld",&t);
    while (t--) {
        long int n;
        scanf("%ld",&n);
        printf("%lld\n",cnt[n]);
    }
    return 0;
}
