/*
Link:https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/
Learning from gfg and youtube videos
*/

#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
/*==========================================FUNCTIONS====================================*/
string makenewstring(string s){
    string newstr="@";
    for(long int i=0;i<s.size();i++){
        newstr+="#"+s.substr(i,1);
    }
    newstr+="#$";
    return newstr;
}
void solve() {
   string s;
   cin>>s;
   string q=makenewstring(s);
   long int n=q.size();
   long int p[n+1]={0};
   long int r=0,c=0;
   for(long int i=1;i<n-1;i++){
       long int imirror=c-(i-c);
       if(r>i){
           p[i]=min(r-i,p[imirror]);
       }
       while(q[i+1+p[i]]==q[i-1-p[i]])
           p[i]++;

       if(i+p[i]>r){
           c=i;
           r=i+p[i];
       }
   }
   long int maxpalin=0,maxidx=0;
   for(long int i=1;i<n-1;i++){
       if(p[i]>maxpalin){
           maxpalin=p[i];
           maxidx=i;
       }
   }

   cout<<maxpalin<<"\n";//<<maxidx<<" "<<(maxidx-1-maxpalin)/2<<" "<<endl;
   cout<<s.substr((maxidx-1-maxpalin)/2,maxpalin)<<endl;
}
/*==========================================MAIN====================================*/
int main() {
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
//    long int t;
//    cin>>t;
    solve();
    return 0;
}

