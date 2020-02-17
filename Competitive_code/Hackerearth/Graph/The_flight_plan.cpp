/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int tim[1005],from[1005];
int n,m,t,c;
void bfs(int s,int end) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i:v[u]) {
            if (!vis[i]) {
                from[i] = u;
                vis[i] = 1;
                if (i == end)
                    return;
                q.push(i);
            }
        }
    }
}
int main() {
    cin >> n >> m >> t >> c;
    if (n == 1) {
        cout << "1\n1";
        return 0;
    }
    for (long int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int x, y;
    cin >> x >> y;
    for (long int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end());

    bfs(x, y);
    vector<int> ans;
    ans.push_back(y);
    int s = from[y], cnt = 1;
    while (s != x) {
        ans.push_back(s);
        s = from[s];
        cnt++;
    }
    ans.push_back(x);
    cnt++;
    cout << cnt << endl;
    for (long int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}
