/*
Link: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/mr-president/
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
vector<pair<long int ,long int > > graph[MAX];
bool vis[MAX]={false};
priority_queue<long int > vec;
unsigned long long int mincost=0;
void prim_algo(long int x) {
    priority_queue<pair<long int, long int>, vector<pair<long int, long int> >, greater<pair<long int, long int> > > pq;
    pair<long int, long int> p;
    pq.push(make_pair(0, x));
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();
        long int x = p.second;
        if (vis[x] == true)
            continue;

        mincost += p.first;
        vec.push(p.first);
        vis[x] = true;
        for (long int i = 0; i < graph[x].size(); i++) {
            long int y = graph[x][i].second;
            if (!vis[y])
                pq.push(graph[x][i]);
        }
    }
}
int main() {
    long int n, m, k, x, y, cost;
    cin >> n >> m >> k;
    for (long int i = 0; i < m; i++) {
        cin >> x >> y >> cost;
        graph[x].push_back(make_pair(cost, y));
        graph[y].push_back(make_pair(cost, x));
    }
    prim_algo(1);
    bool ff = false;
    for (long int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            ff = true;
            break;
        }
    }
    if (ff) {
        cout << "-1\n";
        return 0;
    }
    if (mincost <= k)
        cout << "0\n";
    else {
        long int cnt = 0;
        while (vec.empty() == false && mincost > k) {
            //cout<<cost<<" "<<vec.top()<<"\n";
            mincost = mincost - vec.top() + 1;
            vec.pop();
            cnt++;
        }
        if (mincost <= k)
            cout << cnt << endl;
        else
            cout << "-1\n";
    }
}
