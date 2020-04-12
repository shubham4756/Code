/*
Link:https://www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/largest-square-3d7a938a/
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;
int main() {
    long int n;
    cin >> n;
    map<int, set<int> > mp;
    for (long int i = 0; i < n; i++) {
        long int a, b;
        cin >> a >> b;
        mp[a].insert(b);
    }
    pair<int, int> ans = {0, 0};
    int max_side = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        int tpx = it->first;
        for (auto y1 = mp[tpx].begin(); y1 != mp[tpx].end(); y1++) {
            for (auto y2 = next(y1); y2 != mp[tpx].end(); y2++) {
                int side = (*y2) - (*y1);
                if (side < max_side || (side == max_side && *y1 >= ans.second))
                    continue;
                auto x2 = tpx + side;
                if (mp[x2].count(*y2) && mp[x2].count(*y1)) {
                    max_side = side;
                    ans = {tpx, *y1};
                }
            }
        }
    }
    if (max_side)
        cout << ans.first << " " << ans.second << endl;
    else
        cout << "-1\n";
    return 0;
}
