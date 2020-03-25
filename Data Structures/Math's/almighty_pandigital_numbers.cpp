/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/mancunian-and-pandigital-numbers-1/
*/

#include<bits/stdc++.h>
using namespace std;
long int cnt[1000005];
int check(long int n) {
    long int a[10] = {0};
    int xx = 0;
    while (n) {
        a[n % 10]++;
        n = n / 10;
        xx++;
    }
    if (xx > 9)
        return 0;
    for (int i = 1; i <= xx; i++)
        if (a[i] != 1)
            return 0;
    return 1;
}
void pre() {
    cnt[0] = 0;
    for (long int i = 1; i < 1000005; i++)
        cnt[i] = check(i);

    for (long int i = 1; i < 1000005; i++)
        cnt[i] += cnt[i - 1];
}
int main() {
    pre();
    long int t;
    cin >> t;
    while (t--) {
        long int l, r;
        cin >> l >> r;
        cout << cnt[r] - cnt[l - 1] << endl;
    }
    return 0;
}
