/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/
Learning:https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
*/

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
long int V,E;
bool ap[200],vis[200];
long int parent[200],low[200],dist[200],ttime=0;
vector<long int > gp[200];
/*==========================================FUNCTIONS====================================*/
void APUtil(long int u) {
    vis[u] = true;
    long int child = 0;
    ttime++;
    dist[u] = low[u] = ttime;
    for (auto it = gp[u].begin(); it != gp[u].end(); it++) {
        long int v = *it;
        if (!vis[v]) {
            child++;
            parent[v] = u;
            APUtil(v);
            low[u] = min(low[u], low[v]);

            //check first condition
            if (parent[u] == -1 && child > 1)
                ap[u] = true;
            //check second condtion
            if (parent[u] != -1 && low[v] >= dist[u])
                ap[u] = true;
        } else if (v != parent[u]) {
            low[u] = min(low[u], dist[v]);
        }
    }
}
void findarticulation() {
    for (long int i = 0; i <= V; i++) {
        ap[i] = false;
        vis[i] = false;
        parent[i] = -1;
    }
    for (long int i = 1; i <= V; i++)
        if (vis[i] == false)
            APUtil(i);
}
void solve() {
    cin >> V >> E;
    for (long int i = 0; i < E; i++) {
        long int x, y;
        cin >> x >> y;
        gp[x].push_back(y);
        gp[y].push_back(x);
    }
    findarticulation();
    long int q;
    cin >> q;
    while (q--) {
        long int n;
        cin >> n;
        if (ap[n]) cout << "Satisfied " << gp[n].size() << endl;
        else cout << "Not Satisfied \n";
    }
}
/*==========================================MAIN====================================*/
int main() {
//        ios_base::sync_with_stdio(false);
//        cin.tie(NULL);
//    long int t;
//    cin >> t;
//    while (t--)
    solve();
    return 0;
}
