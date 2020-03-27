/*
Link:https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/save-girlfriend/description/
for learn more see editorial
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    long int t;
    scanf("%ld",&t);
    while (t--) {
        long int a, b;
        scanf("%ld",&a);
        scanf("%ld",&b);
        long long arr[10010]={0};
        long long mx = -1, cnt = 0;
        for (long long i = 1; i <= b; i++) {
            long long sq = i * i;
            long long first_div = (((a - 1) / i) + 1) * i;
            for (long long j = first_div; j <= b; j += i) {
                if (j < sq)
                    continue;
                else if (j == sq)
                    arr[j - a]++;
                else arr[j - a] += 2;
            }
        }
        for (long long i = a; i <= b; i++) {
            if (arr[i - a] > mx) {
                cnt = 1;
                mx = arr[i - a];
            } else if (mx == arr[i - a])
                cnt++;
        }
        printf("%lld\n",cnt + 1);
    }
    return 0;
}
