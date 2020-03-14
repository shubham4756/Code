/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/3-types/
*/

#include<bits/stdc++.h>
using namespace std;
long int sz[2][100005];
void pre() {
    for (long int i = 0; i < 100005; i++) {
        sz[0][i] = i;
        sz[1][i] = i;
    }
}
long int root(long int i,long int x) {
    while (sz[i][x] != x) {
        sz[i][x] = sz[i][sz[i][x]];
        x = sz[i][x];
    }
    return x;
}
void makeunion(long int i,long int x,long int y) {
    x = root(i, x);
    y = root(i, y);
    sz[i][x] = sz[i][y];
}
vector<pair<long ,long > > vv[3];
int main() {
    long int n, m;
    cin >> n >> m;
    pre();
    long int a, b, c;
    for (long int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (c == 1)
            vv[0].push_back(make_pair(a, b));
        else if (c == 2)
            vv[1].push_back(make_pair(a, b));
        else
            vv[2].push_back(make_pair(a, b));
    }
    long int ans = 0;
    for (long int i = 2; i >= 0; i--) {
        for (long int j = 0; j < vv[i].size(); j++) {
            long int x = vv[i][j].first, y = vv[i][j].second;
            if (i == 2) {
                if (root(0, x) != root(0, y) && root(1, x) != root(1, y)) {
                    makeunion(0, x, y);
                    makeunion(1, x, y);
                } else
                    ans++;
            } else if (i == 1) {
                if (root(0, x) != root(0, y)) {
                    makeunion(0, x, y);
                } else ans++;
            } else {
                if (root(1, x) != root(1, y)) {
                    makeunion(1, x, y);
                } else
                    ans++;
            }
        }
    }
    long int men = sz[0][1], women = sz[1][1];
    bool ff = false;
    for (long int i = 2; i <= n; i++) {
        if ( root(0,men) != root(0,sz[0][i])) {
            ff = true;
            break;
        }
        if ( root(1,women) != root(1,sz[1][i])) {
            ff = true;
            break;
        }
    }
    if (ff)
        cout << "-1\n";
    else
        cout << ans << endl;
    return 0;
}
