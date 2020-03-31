/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/sg-and-graphs/
Learning:https://www.geeksforgeeks.org/bridge-in-a-graph/
Learning:https://www.geeksforgeeks.org/check-removing-given-edge-disconnects-given-graph/
*/

//below this code is other code which giving complete right answer my code giving in 2 test case in only 2 line why that idk

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
long int V,E,low[100005],dist[100005],parent[100005],ttime=0;
bool vis[100005];
vector<long int > gp[100005];
pair<long int,long int> mpp[1000005];
set<pair<long int,long int > > bridge;
/*==========================================FUNCTIONS====================================*/
void DFStill(long int u){
    vis[u]=true;
    ttime++;
    low[u]=dist[u]=ttime;
    for(auto it=gp[u].begin();it!=gp[u].end();it++){
        long int v=*it;
        if(!vis[v]){
            parent[v]=u;
            DFStill(v);
            low[u]=min(low[u],low[v]);

            if(low[v]>dist[u])
                bridge.insert({u,v});
        } else if(v!=parent[u])
            low[u]=min(low[u],dist[v]);
    }
}
void findallbridge(){
    for(long int i=0;i<=V;i++) {
        parent[i] = -1;
        vis[i] = false;
    }
    for(long int i=1;i<=V;i++)
        if(!vis[i])
            DFStill(i);
}
void solve() {
    long int Q;
    scanf("%ld",&V);
    scanf("%ld",&E);
    scanf("%ld",&Q);
    for(long int i=0;i<E;i++){
        long int x,y,z;
        scanf("%ld",&x);
        scanf("%ld",&y);
        scanf("%ld",&z);
        gp[x].push_back(y);
        gp[y].push_back(x);
        mpp[z]={x,y};
    }
    findallbridge();
    while(Q--){
        long int id;
        scanf("%ld",&id);
        long int x=mpp[id].first,y=mpp[id].second;
        if(bridge.find({x,y})!=bridge.end() || bridge.find({y,x})!=bridge.end())
            printf("YES\n");
        else
            printf("no\n");
    }
}
/*==========================================MAIN====================================*/
int main() {
     solve();
    return 0;
}

//---------------second code
#include<bits/stdc++.h>

using namespace std;

const int mx= 1e6+5;

int parent[mx];
bool vis[mx];
int disc[mx];
int low[mx];
map <int,int> bridge;
vector<pair<int,int>>adj[mx];

void apufind(int u)
{
     static int time =0;
     disc[u]=low[u]=time++;
     vis[u]=true;
     for(int i=0;i<(int)adj[u].size();i++)
     {
         int v=adj[u][i].first;
         int id=adj[u][i].second;
         if(!vis[v])
         {
             parent[v]=u;
             apufind(v);
             low[u]=min(low[u],low[v]);

             if(low[v]>disc[u])
             {
                 bridge[id]=1;
             }
         }
         else if( v!=parent[u])
         {
             low[u]=min(disc[v],low[u]);
         }
     }
}

int main()

{
    int n,m,id,k;
    scanf("%d%d%d",&n,&m,&k);
    int u,v;
    int i=1;
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&id);
        adj[u].push_back(make_pair(v,id));
        adj[v].push_back(make_pair(u,id));
    }
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        vis[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            apufind(i);
        }
    }
    int p,g;
    while(k--)
    {
        scanf("%d",&g);
        if(bridge[g]==0)
        {
           printf("no\n");
        }
        else
        {
             printf("YES\n");
        }
    }

    return 0;
}
