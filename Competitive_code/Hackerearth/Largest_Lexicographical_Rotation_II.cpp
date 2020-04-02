/*
Link:https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/largest-lexicographical-rotation-ii/description/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/

/*==========================================FUNCTIONS====================================*/
void solve() {
    string s;
    cin>>s;
    long int len=s.size();
    s+=s;
    long int i=0,j=1,k=0,l=0;
    for(;j<len;){
        for(k=0; k<len && s[i+k]==s[j+k];++k);
        if(k>=len) break;
        if(s[i+k]>s[j+k])
            j+=(k+1);
        else{
            l=i+k;
            i=j;
            j=max(l,j)+1;
        }
    }
    cout<<s.substr(i,len)<<endl;
}
/*==========================================MAIN====================================*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    long int t;
//    cin>>t;
//    while(t--)
       solve();
    return 0;
}
