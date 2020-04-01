/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/
*/

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
long int V,E,node=0;
vector<long int > g1[100005];
vector<long int > g2[100005];
bool vis[100005];
int path[100005];
stack<long int > stc;
queue<long int > q;
/*==========================================FUNCTIONS====================================*/
void DFSSS(long int u) {
    vis[u] = true;
    for (long int i = 0; i < g1[u].size(); i++) {
        long int v = g1[u][i];
        if (!vis[v])
            DFSSS(v);
    }
    stc.push(u);
}
void DFSUU(long int u) {
    vis[u] = true;
    q.push(u);
    for (long int i = 0; i < g2[u].size(); i++) {
        long int v = g2[u][i];
        if (!vis[v])
            DFSUU(v);
    }
}
void  solve() {
    cin >> V >> E;
    long int C = 0, D = 0;
    for (long int i = 0; i < E; i++) {
        long int x, y;
        cin >> x >> y;
        g1[x].push_back(y);
        g2[y].push_back(x);
    }
    for (long int i = 0; i <= V; i++) {
        vis[i] = false;
        path[i] = 0;
    }
    for (long int i = 1; i <= V; i++)
        if (!vis[i])
            DFSSS(i);

    for (long int i = 0; i <= V; i++)
        vis[i] = false;
    while (!stc.empty()) {
        long int u = stc.top();
        stc.pop();
        if (!vis[u])
            DFSUU(u);
        if(q.size()>1)
        {
            while(!q.empty()) {
                path[q.front()] = 1;
                q.pop();
            }
        }
        else{
            while(!q.empty())
                q.pop();
        }
    }
    for(long int i=1;i<=V;i++)
        cout<<path[i]<<" ";
}
/*==========================================MAIN====================================*/
int main() {
    solve();
    return 0;
}

