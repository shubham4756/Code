/*
Link:https://www.hackerearth.com/problem/algorithm/avoiding-networked-paths-revisited-38d27ffb/?layout=old
*/

#include<bits/stdc++.h>
using namespace std;

const int Md=1e9+7;
const int N=1010;
const long long p0=107;
const long long p1=1361;
const long long p2=10000019;
const int k0=2;
const int k1=2;
const int k2=1;

long long dp[N][N][k0+1][k1+1][k2+1];
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<long long> > a(h, vector<long long>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int> > b0(h, vector<int>(w));
    vector<vector<int> > b1(h, vector<int>(w));
    vector<vector<int> > b2(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            while (a[i][j] % p0 == 0) {
                a[i][j] /= p0;
                b0[i][j]++;
            }
            while (a[i][j] % p1 == 0) {
                a[i][j] /= p1;
                b1[i][j]++;
            }
            while (a[i][j] % p2 == 0) {
                a[i][j] /= p2;
                b2[i][j]++;
            }

            b0[i][j] = min(k0, b0[i][j]);
            b1[i][j] = min(k1, b1[i][j]);
            b2[i][j] = min(k2, b2[i][j]);
        }
    }

    dp[0][0][b0[0][0]][b1[0][0]][b2[0][0]] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int x0 = 0; x0 <= k0; x0++) {
                for (int x1 = 0; x1 <= k1; x1++) {
                    for (int x2 = 0; x2 <= k2; x2++) {
                        if (i + 1 < h) {
                            dp[i + 1][j][min(k0, x0 + b0[i + 1][j])][min(k1, x1 + b1[i + 1][j])][min(k2, x2 + b2[i +
                                                                                                                 1][j])] =
                                    (dp[i + 1][j][min(k0, x0 + b0[i + 1][j])][min(k1, x1 + b1[i + 1][j])][min(k2, x2 +
                                                                                                                  b2[i +
                                                                                                                     1][j])] +
                                     dp[i][j][x0][x1][x2]) % Md;
                        }
                        if (j + 1 < w) {
                            dp[i][j + 1][min(k0, x0 + b0[i][j + 1])][min(k1, x1 + b1[i][j + 1])][min(k2, x2 + b2[i][j +
                                                                                                                    1])] =
                                    (dp[i][j + 1][min(k0, x0 + b0[i][j + 1])][min(k1, x1 + b1[i][j + 1])][min(k2, x2 +
                                                                                                                  b2[i][j +
                                                                                                                        1])] +
                                     dp[i][j][x0][x1][x2]) % Md;
                        }
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int x0 = 0; x0 <= k0; x0++) {
        for (int x1 = 0; x1 <= k1; x1++) {
            for (int x2 = 0; x2 <= k2; x2++) {
                if (x0 < k0 || x1 < k1 || x2 < k2) {
                    ans = (ans + dp[h - 1][w - 1][x0][x1][x2]) % Md;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
