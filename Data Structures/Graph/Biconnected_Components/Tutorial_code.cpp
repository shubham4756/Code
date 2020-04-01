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



















//int mtx[1005][1005];
//long int n,m;
//bool check(long int x,long int y){
//    if(x<=0 || y<=0 || x>n || y>m)
//        return false;
//    return true;
//}
//void solve(){
//    cin>>n>>m;
//    char c;
//    bool vis[n+2][m+2];
//    for(long int i=1;i<=n;i++){
//        for(long int j=1;j<=m;j++){
//            cin>>c;
//            if(c=='+')
//                mtx[i][j]=4;
//            else if(c=='x')
//                mtx[i][j]=2;
//            else
//                mtx[i][j]=0;
//
//            vis[i][j]=false;
//        }
//    }
//    int dx4[]={0,0,1,-1};
//    int dy4[]={1,-1,0,0};
//    int dx2[]={-1,1};
//    int dy2[]={-1,1};
//            //x yam         // y yam        //step       //power used or not
//    queue<pair<pair<long int,long int>,pair<long int,bool> > > q;
//    q.push({{1,1},{1,false}});
//    vis[1][1]=true;
//    bool forans=false;
//    long int cnt=0;
//    long int ans=INT_MAX;
//    while(!q.empty()){
//        cnt++;
//        if(cnt==1001)
//            break;
//        long int xx=q.front().first.first,yy=q.front().first.second,step=q.front().second.first;
//        bool power=q.front().second.second;
//        if(xx==n && yy==m){
//            forans=true;
//            ans=min(ans,step);
//            break;
//        }
//        q.pop();
//        if(mtx[xx][yy]==4){
//            for(long int i=0;i<4;i++){
//                if(check(xx+dx4[i],yy+dy4[i])){
//                    //vis[xx+dx4[i]][yy+dy4[i]]=true;
//                    //cout<<xx<<" "<<yy<<" "<<xx+dx4[i]<<" "<<yy+dy4[i]<<" ---is for +"<<endl;
//                    q.push({{xx+dx4[i],yy+dy4[i]},{step+1,power}});
//                }
//            }
//        }
//        else if(mtx[xx][yy]==2){
//            for(long int i=0;i<2;i++){
//                if(check(xx+dx2[i],yy+dy2[i])){
//                    //vis[xx+dx2[i]][yy+dy2[i]]=true;
//                    //cout<<xx<<" "<<yy<<" "<<xx+dx2[i]<<" "<<yy+dy2[i]<<" ---is for X"<<endl;
//                    q.push({{xx+dx2[i],yy+dy2[i]},{step+1,power}});
//                }
//            }
//        }else{
//            //if we make it +
//            if(power==false){
//                for(long int i=0;i<2;i++){
//                    if(check(xx+dx2[i],yy+dy2[i])){
//                        //vis[xx+dx2[i]][yy+dy2[i]]=true;
//                        //cout<<xx<<" "<<yy<<" "<<xx+dx2[i]<<" "<<yy+dy2[i]<<" ---is for maked x"<<endl;
//                        q.push({{xx+dx2[i],yy+dy2[i]},{step+1,true}});
//                    }
//                }
//                //if we make it x
//                for(long int i=0;i<4;i++){
//                    if(check(xx+dx4[i],yy+dy4[i])){
//                        //vis[xx+dx4[i]][yy+dy4[i]]=true;
//                        //cout<<xx<<" "<<yy<<" "<<xx+dx4[i]<<" "<<yy+dy4[i]<<" ---is for maked +"<<endl;
//                        q.push({{xx+dx4[i],yy+dy4[i]},{step+1,true}});
//                    }
//                }
//            }
//            //if we not use it
//        }
//    }
//    if(forans)
//    cout<<ans<<" "<<"Yes\n"<<endl;
//    else
//        cout<<"-1\n";
//}
/*const int MAXN=1000005;
int mp[MAXN];
void solve() {
    long int n;
    cin>>n;
    long int a[n];
    memset(mp,0,sizeof(mp));
    for(long int i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]=i;
    }
    sort(a,a+n);
    long int pre=mp[a[0]],ans=1;
    for(long int i=1;i<n;i++){
        long int idx=mp[a[i]];
        //cout<<mp[a[i]];
        if(idx<pre)
        {   //cout<<pre<<" "<<idx<<" "<<a[i]<<endl;
            ans++;
        }
        pre=idx;
    }
    cout<<ans<<endl;
}*/
/*void solve(){
  long int x;
  vector<pair<long long int,long int > > v;
  long long int sum=0;
  for(long int i=1;i<=3;i++){
      cin>>x;
      sum+=x;
      v.push_back(make_pair(x,i));
  }
  sort(v.begin(),v.end());
  if(v[0].second==2){
      long long int ans=0,tp=(v[0].first+v[2].first);
      if(tp%3!=0)
          ans++;
      ans+=tp/3;
      ans=max(ans,v[1].first);
      cout<<ans<<endl;
  }else if(v[2].second==2){
      long long int ans=sum/3;
      if(sum%3!=0)
          ans++;
      cout<<ans<<endl;
  }
  else{

  }
}*/
