/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/smart-travel-agent/
*/

#include<bits/stdc++.h>
using namespace std;
vector<long int> ans;
long int maxofmin=INT_MIN;
long int val[102][102];
vector<long int > gp[102];
bool vis[102]={false};
void findans(long int s,long int d,long int minofmax,vector<long int> &temp) {
    //cout<<"start->"<<s<<" "<<d<<endl;
    vis[s] = true;
    temp.push_back(s);
    if (s == d) {
        //cout<<"in equal \n";
        if (minofmax >= maxofmin) {
            if (minofmax == maxofmin && temp < ans) {
                ans = temp;
            } else ans = temp;
            maxofmin = minofmax;
        }
    } else {
        for (long int i = 0; i < gp[s].size(); i++) {
            //cout<<s<<" "<<gp[s][i]<<" "<<minofmax<<" "<<val[s][gp[s][i]]<<endl;
            if (!vis[gp[s][i]]) {
                findans(gp[s][i], d, min(minofmax, val[s][gp[s][i]]), temp);
            }
        }
    }
    vis[s] = false;
    temp.pop_back();
}
int main() {
    long int n, m;
    cin >> n >> m;
    for (long int i = 0; i < m; i++) {
        long int x, y, w;
        cin >> x >> y >> w;
        gp[x].push_back(y);
        gp[y].push_back(x);
        val[x][y] = w;
        val[y][x] = w;
    }
    long int s, d, person;
    cin >> s >> d >> person;
    long int minofmax = INT_MAX;
    vector<long int> temp;
    findans(s, d, minofmax, temp);
    //cout<<maxofmin<<"---------\n";
    long int trip;
    trip = person / (maxofmin - 1);
    if (person % (maxofmin - 1) != 0)
        trip++;

    for (long int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    cout << trip << endl;
    return 0;
}
