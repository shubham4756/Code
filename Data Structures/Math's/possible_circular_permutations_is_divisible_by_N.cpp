/*
Link:https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/ma5terminds-birthday-party/
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
long long int phi[MAXN]={0};
void pre1() {               //--here it's not required
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
}
bool prime[MAXN];
long int NoPri[MAXN];
void pre() {            //*****it's used in main function
    prime[0]=true;
    prime[1]=true;
    for (long int i = 2; i * i < MAXN; i++) {
        if (!prime[i]) {
            for (long int j = i * i; j < MAXN; j += i)
                prime[j] = true;
        }
    }
    prime[4]=false;
    NoPri[0]=0;
    for(long int i=1;i<MAXN;i++) NoPri[i]=NoPri[i-1]+(!prime[i]);
}
long int euler(long int n) {               //--here it's not required
    long int xx = 0, res = n;
    for (long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}
long int numberofdiv(long int n) {  //--here it's not required
    long int xx = 1;
    for (long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i)
                xx++;
            else
                xx += 2;
        }
    }
    return xx;
}
bool isPrime(long int n) {
    for (long int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main() {
    pre();
    long int t;
    scanf("%ld",&t);
    while (t--) {
        long int l,r;       //circuler permutaion is (n-1)! so for divide with it n we have to check
        //that n is prime or not
        scanf("%ld",&l);
        scanf("%ld",&r);
        printf("%ld\n",(r-l+1)-(NoPri[r]-NoPri[l-1]));
    }
    return 0;
}
