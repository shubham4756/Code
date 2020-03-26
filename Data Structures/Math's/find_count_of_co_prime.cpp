/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/too-much-to-count-fb914aed/
Learning:https://www.geeksforgeeks.org/eulers-totient-function/
Learning:https://www.geeksforgeeks.org/eulers-totient-function-for-all-numbers-smaller-than-or-equal-to-n/
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
long long int phi[MAXN]={0};
void pre() {            //-------------find co_prime for number 1 to n
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
long int euler(long int n) {   //---------find co_primes for individual number
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
long int numberofdiv(long int n) {
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
int main() {
    pre();
    long int t;
    scanf("%ld", &t);
    while (t--) {
        long int n;
        scanf("%ld", &n);
        //long int totient = euler(n);
        long int divisor = numberofdiv(n);
        //cout<<phi[n]<<endl;
        printf("%ld\n", n - phi[n] - divisor);
    }
    return 0;
}
