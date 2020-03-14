/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/robot-in-grid-b7d391f7/
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> v[1001];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void bfs(char** edge,bool** vis,int n,int m,int s1,int s2,int** dis) {
    vis[s1][s2] = true;
    queue<pair<int, int> > q;
    q.push({s1, s2});
    while (!q.empty()) {
        pair<int, int> p;
        p = q.front();
        q.pop();
        vis[p.first][p.second] = true;
        for (int i = 0; i < 4; i++) {
            int xx = p.first + dx[i], yy = p.second + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && edge[xx][yy] == 'O' && vis[xx][yy] == false) {
                q.push({xx, yy});
                vis[xx][yy] = true;
                dis[xx][yy] = dis[p.first][p.second] + 1;
            }
        }
    }
    return;
}
int main() {
    int n, m, q;
    cin>>n>>m>>q;
    char **edge = new char *[n];
    bool **vis = new bool *[n];
    int **dis = new int *[n];
    for (int i = 0; i < n; i++) {
        edge[i] = new char[m];
        vis[i] = new bool[m];
        dis[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> edge[i][j];
            vis[i][j] = false;
            dis[i][j] = 0;
        }
    }
    int d1, d2, s1, s2;
    cin >> s1 >> s2;
    bfs(edge, vis, n, m, s1 - 1, s2 - 1, dis);
    while (q--) {
        cin >> d1 >> d2;
        if (vis[d1 - 1][d2 - 1])
            cout << dis[d1 - 1][d2 - 1] << endl;
        else
            cout << "-1\n";
    }
}
