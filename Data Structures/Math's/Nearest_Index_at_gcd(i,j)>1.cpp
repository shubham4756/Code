/*
Link:https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/mike-and-gcd-issues/
Learning:https://www.geeksforgeeks.org/nearest-element-least-one-common-prime-factor/
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
const int INF = INT_MAX;
int primedivisor[MAX], dist[MAX], pos[MAX], divInd[MAX],n,arr[MAX];
vector<int> divisors[MAX];
void sieveOfEratosthenes() {
    for (int i = 2; i * i < MAX; ++i) {
        if (!primedivisor[i])
            for (int j = i * i; j < MAX; j += i)
                primedivisor[j] = i;
    }
    for (int i = 1; i < MAX; ++i)
        if (!primedivisor[i])
            primedivisor[i] = i;
}
void findDivisors() {
    for (int i = 0; i < MAX; ++i)
        pos[i] = divInd[i] = -1, dist[i] = INF;

    for (int i = 0; i < n; ++i) {
        int num = arr[i];
        while (num > 1) {
            int div = primedivisor[num];
            divisors[i].push_back(div);
            while (num % div == 0)
                num /= div;
        }
    }
}
void nearestGCD() {
    findDivisors();
    for (int i = 0; i < n; ++i) {
        for (auto &div: divisors[i]) {
            if (divInd[div] == -1)
                divInd[div] = i;
            else {
                int ind = divInd[div];
                divInd[div] = i;
                if (dist[i] > abs(ind - i)) {
                    dist[i] = abs(ind - i);
                    pos[i] = ind + 1;
                }
                if (dist[ind] > abs(ind - i)) {
                    dist[ind] = abs(ind - i);
                    pos[ind] = i + 1;
                }
            }
        }
    }
}
int main() {
    sieveOfEratosthenes();
    cin >> n;
    for (long int i = 0; i < n; i++)
        cin >> arr[i];
    nearestGCD();
    for (long int i = 0; i < n; i++)
        cout << pos[i] << " ";
    return 0;
}
