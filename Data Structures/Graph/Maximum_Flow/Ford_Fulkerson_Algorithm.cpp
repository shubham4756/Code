/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/practice-problems/algorithm/find-the-flow/
Learning:https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
long int flow[50][50],V=0;
/*==========================================FUNCTIONS====================================*/
bool bfs(long int s,long int t,long int parent[]) {
    bool vis[V + 1];
    memset(vis, false, sizeof(vis));

    queue<long int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        long int u = q.front();
        q.pop();

        for (long int v = 0; v < V; v++) {
            if (vis[v] == false && flow[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                vis[v] = true;
            }
        }
    }
    return (vis[t] == true);
}
long int maxFlow(long int s,long int t) {
    long int parent[V + 1];
    long int max_flow = 0;
    while (bfs(s, t, parent)) {
        long int path_flow = INT_MAX;
        for (long int v = t; v != s; v = parent[v]) {
            long int u = parent[v];
            path_flow = min(path_flow, flow[u][v]);
        }
        for (long int v = t; v != s; v = parent[v]) {
            long int u = parent[v];
            flow[u][v] -= path_flow;
            flow[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
void solve() {
    long int E;
    cin >> E;
    for (long int i = 0; i < E; i++) {
        char a, b;
        long int ff;
        cin >> a >> b >> ff;
        flow[a - 'A'][b - 'A'] = ff;
        V = max({V, (long) a - 'A', (long) b - 'A'});
    }
    V += 2;
    char st = 'S', dn = 'T';
    cout << maxFlow(st - 'A', dn - 'A');
}
/*==========================================MAIN====================================*/
int main() {
//    long int t;
//    cin>>t;
//    while(t--)
       solve();
    return 0;
}
