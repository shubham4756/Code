/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/
*/



#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
long int V,E,ttime=0,eve=0,odd=0;
vector<long int > gp[100];
bool vis[100];
stack<pair<long int,long int > > st;
long int dist[100],low[100],parent[100],child[100];
/*==========================================FUNCTIONS====================================*/
void DFS(long int u) {
    vis[u] = true;
    ttime++;
    dist[u] = low[u] = ttime;
    for (long int i = 0; i < gp[u].size(); i++) {
        long int v = gp[u][i];
        if (!vis[v]) {
            parent[v] = u;
            child[v]++;
            st.push({u, v});
            DFS(v);
            low[u] = min(low[u], low[v]);

            if ((dist[u] == 1 && child[u] > 1) || (low[v] >= dist[u])) {
                set<long int> s;
                while (st.top().first != u || st.top().second != v) {
                    s.insert(st.top().first);
                    s.insert(st.top().second);
                    st.pop();
                }
                s.insert(st.top().first);
                s.insert(st.top().second);
                st.pop();
                if (s.size() % 2 == 0) eve++;
                else odd++;
            }
        } else if (v != parent[u] && dist[v] < low[u]) {
            low[u] = min(low[u], dist[v]);
            st.push({u, v});
        }
    }
}
void solve() {
    cin >> V >> E;
    for (long int i = 0; i < E; i++) {
        long int x, y;
        cin >> x >> y;
        gp[x + 1].push_back(y + 1);
        gp[y + 1].push_back(x + 1);
    }
    parent[1] = -1;
    for (long int i = 1; i <= V; i++) {
        if (!vis[i])
            DFS(i);
    }
    set<long int> s;
    while (!st.empty()) {
        s.insert(st.top().first);
        s.insert(st.top().second);
        st.pop();
    }
    if (s.size() != 0 and s.size() & 1)odd++;
    else if (s.size() != 0) eve++;
    cout << odd << " " << eve << endl;
}
/*==========================================MAIN====================================*/
int main() {
    solve();
    return 0;
}
