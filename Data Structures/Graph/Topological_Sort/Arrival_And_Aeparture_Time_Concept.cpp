/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
long int V,Time=0;
vector<long int> gp[200005];
bool vis[200005]={false};
long int arrTime[200005]={0},depTime[200005]={0};
/*==========================================FUNCTIONS====================================*/
void DFS(long int u) {
    vis[u] = true;
    arrTime[u] = Time;
    Time++;
    for (long int i = 0; i < gp[u].size(); i++) {
        long int v = gp[u][i];
        if (!vis[v])
            DFS(v);
    }
    depTime[u] = Time;
    Time++;
}
void solve() {
    cin >> V;
    for (long int i = 0; i < V - 1; i++) {
        long int x, y;
        cin >> x >> y;
        gp[x].push_back(y);
    }
    for (long int i = 1; i <= V; i++)
        if (!vis[i])
            DFS(i);
    long int q;
    cin >> q;
    while (q--) {
        long int ty, x, y;
        cin >> ty >> x >> y;
        if (ty == 0) {
            if (arrTime[y] > arrTime[x] && depTime[y] < depTime[x])
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            if (arrTime[y] < arrTime[x] && depTime[y] > depTime[x])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
/*==========================================MAIN====================================*/
int main() {
    solve();
    return 0;
}
