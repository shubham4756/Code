/*
Link:https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/
tutorial question
*/





#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
bool adj[20][20];
long int n,m;
/*==========================================FUNCTIONS====================================*/
bool check(){
    vector<long int> v;
    for(long int i=0;i<n;i++)
        v.push_back(i);

    do{
        bool valid=true;
        for(int i=0; i<v.size()-1; i++){
            if(adj[v[i]][v[i+1]] == false){
                valid=false;
                break;
            }
        }
        if(valid)
            return true;
    }while(next_permutation(v.begin(),v.end()));
    return false;
}
void solve() {
   cin>>n>>m;
   memset(adj,false,sizeof(adj));
   for(long int i=0;i<m;i++){
       long int x,y;
       cin>>x>>y;
       adj[x][y]=true;
       adj[y][x]=true;
   }
   if(check())
       cout<<"YES\n";
   else
       cout<<"NO\n";
}
/*==========================================MAIN====================================*/
int main() {
    solve();
    return 0;
}
