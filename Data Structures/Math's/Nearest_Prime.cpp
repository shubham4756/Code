/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/nearest-prime-a828361b/
Answer: read comments
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int main() {
    bool isPrime[MAX];
    long long int left[MAX], right[MAX];
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (long int i = 2; i * i < MAX; i++) {
        if (isPrime[i]) {
            for (long int j = i * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    }
    left[0] = 0;
    left[1] = 1;
    left[2] = 2;
    long int x = 2;
    for (long int i = 3; i < MAX; i++) {
        if (!isPrime[i])
            left[i] = x;
        else {
            left[i] = i;
            x = i;
        }
    }
    x = INT_MAX;
    for (long int i = MAX-1; i >= 2; i--) {
        if (!isPrime[i])
            right[i] = x;
        else {
            right[i] = i;
            x = i;
        }
    }
    long int t;
    scanf("%ld",&t);
    while (t--) {
        long int n;
        scanf("%ld",&n);
        if (abs(n - left[n]) <= abs(right[n] - n))
            printf("%ld\n",left[n]);
        else
            printf("%ld\n",right[n]);
    }
    return 0;
}
