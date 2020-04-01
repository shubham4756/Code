/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/lonelyisland-49054110/description/
Learning:https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
alse aditorial is open to see
*/

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
long int V,E,ST,in[200005];
vector<long int> gp[200005],ans;
double val[200005]={0},out[200005]={0};
queue<long int > q;
/*==========================================FUNCTIONS====================================*/
void topsort() {
    for (long int i = 1; i <= V; i++)
        if (!in[i])
            q.push(i);

    while (!q.empty()) {
        long int u = q.front();
        q.pop();
        ans.push_back(u);
        for (long int i = 0; i < gp[u].size(); i++) {
            long int v = gp[u][i];
            in[v] -= 1;
            val[v] += (val[u] / out[u]);
            if (in[v] == 0)
                q.push(v);
        }
    }
}
void solve() {
    cin >> V >> E >> ST;
    for (long int i = 0; i < E; i++) {
        long int x, y;
        cin >> x >> y;
        gp[x].push_back(y);
        in[y]++;
        out[x] += 1.0;
    }
    val[ST] = 1;
    topsort();
    double eps = 1e-9;
    double maxx = 0;
    for (long int i = 1; i <= V; i++)
        if (!out[i])
            maxx = max(maxx, val[i]);

    for (long int i = 1; i <= V; i++) {
        if (!out[i] && fabs(val[i] - maxx) <= eps)
            cout << i << " ";
    }
}
/*==========================================MAIN====================================*/
int main() {
    solve();
    return 0;
}
