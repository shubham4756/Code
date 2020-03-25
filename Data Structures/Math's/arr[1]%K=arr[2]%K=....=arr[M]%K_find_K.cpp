/*
Link: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/a-simple-task/
Learning Link: https://www.geeksforgeeks.org/finding-k-modulus-array-element/
Learning Link: https://stackoverflow.com/questions/40238566/find-every-k-such-that-arrik-is-equal-to-for-each-arri
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n;
    cin >> n;
    long int a[n];
    long int maxx = INT_MIN, minn = INT_MAX;
    for (long int i = 0; i < n; i++) {
        cin >> a[i];
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }
    long int d = maxx - minn;
    set<long int> s;
    for (long int i = 2; i <= sqrt(d); i++) {
        if (d % i == 0) {
            s.insert(i);
            s.insert(d / i);
        }
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        long int temp = a[0] % (*it);
        long int j;
        for (j = 1; j < n; j++)
            if (temp != a[j] % (*it))
                break;
        if (j == n)
            cout << (*it) << " ";
    }
    return 0;
}

//second method
#include<bits/stdc++.h>
using namespace std;
int main() {
    long int n;
    scanf("%ld",&n);
    long int a[n];
    long int maxx = INT_MIN, minn = INT_MAX;
    for (long int i = 0; i < n; i++) {
        scanf("%ld",&a[i]);
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }
    long int diff[n - 1], j = 0;
    for (long int i = 0; i < n; i++)
        if (a[i] != minn)
            diff[j++] = a[i] - minn;
    long int g = diff[0];
    for (long int i = 1; i < n - 1; i++)
        g = __gcd(g, diff[i]);
    for (long int i = 2; i <= g; i++)
        if (g % i == 0)
            printf("%ld ",i);
    return 0;
}
