/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/so-np-c559f406/
*/

#include<bits/stdc++.h>
using namespace std;
void dfs(long int node,bool vis[],vector<long int > graph[]){
    vis[node]=true;
    for(long int i=0;i<graph[node].size();i++){
        if(vis[graph[node][i]]==false){
            dfs(graph[node][i],vis,graph);
        }
    }
}
int main(){
    long int n,m,k;
    cin>>n>>m>>k;
    long int x,y;
    vector<long int> graph[n+1];
    for(long int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    long int component=0;
    bool vis[n+1];
    memset(vis,false, sizeof(vis));

    for(long int i=1;i<=n;i++){
          if(vis[i]==false){
              dfs(i,vis,graph);
              component++;
          }
    }
    if(component>k)
        cout<<"-1\n";
    else
        cout<<m-n+k<<endl;
    return 0;
}
