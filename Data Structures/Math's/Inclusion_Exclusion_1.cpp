/*
Link:https://www.hackerearth.com/practice/math/combinatorics/inclusion-exclusion/practice-problems/algorithm/easy-one-4/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
/*=============================================FUNCTIONS======================================*/
void solve(){
    long int N,n;
    cin>>N>>n;
    long int x;
    set<long > s;
    for(long int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    vector<long > a;
    for(auto it=s.begin();it!=s.end();it++)
        a.push_back(*it);
    unsigned long long res=0;
    n=s.size();
    for(long int i=1;i<(1<<n);i++){
        unsigned long long t=1;
        long int cnt=0;
        for(long int j=0;j<n;j++){
            if(i&(1<<j)){
                t*=a[j];
                cnt++;
            }
        }
        t=N/t;
        if(cnt%2)      //if we doing odd number of multiplication than we have to add otherwise minus it 
            res+=t;
        else
            res-=t;
    }
    cout<<res<<endl;
}
/*==============================================MAIN============================================*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

