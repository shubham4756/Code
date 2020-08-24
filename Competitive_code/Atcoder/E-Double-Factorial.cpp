/*
Link: https://atcoder.jp/contests/abc148/tasks/abc148_e
Editorial : https://img.atcoder.jp/abc148/editorial.pdf
*/


/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
const int  MOD=1000000007;
const int N=100010;

void solve(){
    ll n;
    cin>>n;
    if(n%2==1){
        cout<<"0\n";
        return ;
    }
    ll tw=0,fiv=0;
    ll tPower=2,fPower=10;
    while(tPower<=n){
        tw+=n/tPower;
        tPower*=2LL;
    }
    while(fPower<=n){
        fiv+=n/fPower;
        fPower*=5LL;
    }
    ll ans=min(tw,fiv);
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
