/*
Link:https://www.hackerearth.com/practice/algorithms/string-algorithm/z-algorithm/practice-problems/algorithm/cyclic-permutations-15/
Learning:https://www.geeksforgeeks.org/count-of-cyclic-permutations-having-xor-with-other-binary-string-as-0/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
long int n,Z[2000005];
/*==========================================FUNCTIONS====================================*/
void Zalgo(string s){
    long int L=0,R=0,k;
    Z[0] = 0;
    for (long int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R - L] == s[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}
void solve() {
    string a,b;
    cin>>a>>b;
    string s=b;
    s.pop_back();
    b=b+s;
    s=a+"$"+b;
    n=s.length();
    Zalgo(s);
    long int xx=0;
    for(long int i=1;i<n-1;i++){
        if(Z[i]==a.length())
            xx++;
    }
    cout<<xx<<endl;
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
