/*
Link:https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/jump-and-achieve-1-4588741c/
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/

/*==========================================FUNCTIONS====================================*/
void solve() {
    long int q;
    cin>>q;
    while(q--){
        long int x,y;
        cin>>x>>y;
        long int g=__gcd(x,y);
        if((g&(g-1))==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
/*==========================================MAIN====================================*/
int main() {
//    long int t;
//    cin>>t;
//    while(t--)
       solve();
    return 0;
}
