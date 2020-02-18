/*
Link:https://www.spoj.com/problems/NAKANJ/
learning link: https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/
*/

#include<bits/stdc++.h>
using namespace std;
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
typedef struct cordinate cordinate;
struct cordinate{
   long int x,y;
   cordinate () {}
   cordinate(long int xx,long int yy): x(xx), y(yy) {}
};
bool isInside(long int x,long int y)
{
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
        return true;
    return false;
}

void solve(){
    string a,b;
    cin>>a>>b;
    long int x1=a[0]-'a'+1,y1=a[1]-'0';
    long int x2=b[0]-'a'+1,y2=b[1]-'0';
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    pair<cordinate,long int > pr;
    queue<pair<cordinate,long int> > q;
    bool bord[9][9];
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            bord[i][j]=false;

    q.push(make_pair(cordinate(x1,y1),0));
    bord[x1][y1]=true;
    while(!q.empty()){
        pr=q.front();
        q.pop();
        long int dis=pr.second;
        cordinate place;
        place=pr.first;
        long int xx=place.x,yy=place.y;
        //cout<<xx<<" "<<yy<<endl;
        if(xx==x2 && yy==y2){
            cout<<dis<<endl;
            break;
        }
        for(long int i=0;i<8;i++){
            long int tpx=xx+dx[i];
            long int tpy=yy+dy[i];
            if(isInside(tpx,tpy) && !bord[tpx][tpy]){
                q.push(make_pair(cordinate(tpx,tpy),dis+1));
                bord[tpx][tpy]=true;
            }
        }
    }
}
int main()
{
  //      ios_base::sync_with_stdio(false);
  //       cin.tie(NULL);
         long int t;
         scanf("%ld",&t);
         while(t--)
           solve();
    return 0;
}
