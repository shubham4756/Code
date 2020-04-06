/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/palindromic-sub-string-length/
Learning:https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
Learning:https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
*/
//also using dp we can solve......................
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long int Mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3fll;
/*==========================================GLOBALVARIABLE====================================*/
bool prime[10002]={false};
/*=============================================FUNCTIONS======================================*/
long int palindromelength(string s){
    int maxLength = 1;
    int start = 0;
    int len = s.size();
    int low, high;
    for (int i = 1; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && s[low] == s[high])
        {   maxLength = max(maxLength,high - low + 1);
            --low;
            ++high;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && s[low] == s[high])
        {    maxLength = max(maxLength,high - low + 1);
            --low;
            ++high;
        }
    }

    return maxLength;
}
void solve(){
    string s;
    cin>>s;
    long int len=palindromelength(s);
    if(!prime[len])
        printf("PRIME\n");
    else
        printf("NOT PRIME\n");
}
/*==============================================MAIN============================================*/
int main() {
    prime[0]=prime[1]=true;
    for(long int i=2;i*i<=10002;i++){
        if(!prime[i]){
            for(long int j=i*i;j<=10002;j+=i)
                prime[j]=true;
        }
    }
    long int t;
    scanf("%ld",&t);
    while (t--)
        solve();
    return 0;
}
