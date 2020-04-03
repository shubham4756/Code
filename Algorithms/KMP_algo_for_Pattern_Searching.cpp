/*
Link:https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/

/*==========================================FUNCTIONS====================================*/
void solve(){
    string s;
    cin>>s;
    long int n=s.size();
    long int a[n];
    long int len=0,i=1;
    a[0]=0;
    while(i<n){
        if(s[len]==s[i]){
            len++;
            a[i]=len;
            i++;
        }
        else{
            if(len!=0)
                len=a[len-1];
            else{
                a[i]=0;
                i++;
            }
        }
    }
    cout<<a[n-1]<<endl;
}
/*==========================================MAIN====================================*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t;
    cin>>t;
    while(t--)
       solve();
    return 0;
}
