/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/prime-numbers-again/
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
const int maxx=10009;
bool prime[maxx]={false};
long int ans[maxx];
vector<long int> pp;
/*==========================================FUNCTIONS====================================*/
void sieve(){
    prime[1]= true;
    prime[2]=false;
    for(long int i=2;i<maxx;i++){
        if(i==4 || i==27 || i==3125){
            prime[i]=true;
            pp.push_back(i);
        }
        if(!prime[i]){
            pp.push_back(i);
            ans[i]=1;
            for(long int j=i*i;j<maxx;j+=i){
                prime[j]=true;
            }
        }
    }
}
void solve(){
    long int n;
    cin>>n;
    cout<<ans[n]<<endl;
}
/*==========================================MAIN====================================*/
int main() {
    //  ios_base::sync_with_stdio(false);
    //  cin.tie(NULL);
    sieve();
    ans[1]=5*maxx;
   // for(long int i=1;i<10;i++)  cout<<pp[i]<<" ";
    for(long int i=4;i<maxx;i++){
        ans[i]=maxx;
        if(find(pp.begin(),pp.end(),i)!=pp.end()){
            //cout<<i<<endl;
            ans[i]=1;
        }else{
            auto it=lower_bound(pp.begin(),pp.end(),i);
            for(auto x=pp.begin();x!=it;x++){
                ans[i]=min(ans[i],ans[i-*x]+1);
            }
        }
    }
    //cout<<ans[101]<<endl;
    long int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
