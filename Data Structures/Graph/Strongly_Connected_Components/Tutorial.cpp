/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/
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
vector<long int > g1[30];
vector<long int > g2[30];
bool vis[30];
stack<long int > stc;
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
    node++;
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
    memset(vis, false, sizeof(vis));
    for (long int i = 1; i <= V; i++)
        if (!vis[i])
            DFSSS(i);
    memset(vis, false, sizeof(vis));
    while (!stc.empty()) {
        long int u = stc.top();
        stc.pop();
        node = 0;
        if (!vis[u])
            DFSUU(u);

        if (node % 2 == 0)
            D += node;
        else
            C += node;
    }
    //cout<<C<<" "<<D<<endl;
    cout << C - D << endl;
}
/*==========================================MAIN====================================*/
int main() {
    solve();
    return 0;
}
