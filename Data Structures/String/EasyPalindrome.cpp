/*
Link:https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/practice-problems/algorithm/easypalindrome-8671e4e3/description/
Link:https://sohojeprogramming.blogspot.com/2020/03/easypalindrome.html
*/


#include<bits/stdc++.h>
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
string findstr(string s) {
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
   return s.substr((maxidx-1-maxpalin)/2,maxpalin);
}
void solve(){
    long int n,cnt=0;
    cin>>n;
    string ans,s;
    cin>>s;
    ans=s;
    s=findstr(s);
    n=s.size();
    while(n%2==0){
        string d="";
        for(long int i=0;i<n/2;i++)
            d+=s.substr(i,1);
        s=findstr(d);
        n=s.size();
        cnt++;
    }
    cout<<cnt<<endl;
    if(cnt)
        cout<<s<<endl;
    else
        cout<<ans<<endl;
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
