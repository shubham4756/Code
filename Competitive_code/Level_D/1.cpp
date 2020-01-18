//https://codeforces.com/contest/598/problem/D
#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool visited[1001][1001];
int ans[1001][1001],n,m;
int xx=0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<pair<int,int> > v;
bool is_valid(int x,int y)
{ return (x >= 0 && x < n && y >= 0 && y < m); }
void ff(int x,int y)
{     visited[x][y]=true;
    v.push_back(make_pair(x,y));
    for(int i=0;i<4;i++)
    {
        if(!visited[x+dx[i]][y+dy[i]] && is_valid(x+dx[i],y+dy[i]))
        {
            if(a[x+dx[i]][y+dy[i]]=='*')
                xx++;
            else
                ff(x+dx[i],y+dy[i]);
        }
    }
}
int main() {
    int q;
    cin>>n>>m>>q;
    for(long int i=0;i<n;i++)
    {
        for(long int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(long int i=0;i<n;i++)
    {
        for(long int j=0;j<m;j++)
        {
            if(a[i][j]=='.' && !visited[i][j])
            {   v.clear();
                xx=0;
                ff(i,j);
                for (auto it : v) {
                    ans[it.first][it.second]=xx;
                }
            }
        }
    }
    while(q--) {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        cout<<ans[x][y]<<endl;
    }
    return 0;
}


