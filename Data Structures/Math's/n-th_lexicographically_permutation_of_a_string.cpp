/*
Link:https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/word-rank-1/description/
Learning:https://www.geeksforgeeks.org/find-n-th-lexicographically-permutation-string-set-2/?ref=rp
*/

//1st solution giving TLE Time complexity O(n) where is nth permutaion
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//const long MAXN=100;
typedef long long int ll;
ll fact[22];
void solve() {
    char s[22];
    scanf("%s",s);
    ll n;
    scanf("%lld",&n);
    ll cnt[26]={0},len =strlen(s);
    for (ll i = 0; i < len; i++)
        cnt[s[i] - 'a']++;

    ll sum = 0, k = 0;
    char out[len];

    while (sum != n) {
        sum = 0;
        for (ll i = 0; i < 26; i++) {
            if (cnt[i] == 0)
                continue;

            cnt[i]--;

            ll sumx = fact[len - 1 - k];
            for (ll j = 0; j < 26; j++)
                sumx /= fact[cnt[j]];
            sum += sumx;

            if (sum >= n) {
                out[k++] = (char) (i + 'a');
                n -= (sum - sumx);
                break;
            }
            if (sum < n)
                cnt[i]++;
        }
    }

    for (ll i = 25; k < len && i >= 0; i--) {
        if (cnt[i]) {
            out[k++] = (char) (i + 'a');
            cnt[i++]--;
        }
    }

    out[k] = '\0';
    printf("%s\n", out);
}
int main() {
    fact[0] = fact[1] = 1;
    for (ll i = 2; i < 22; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    long t;
    scanf("%lld",&t);
    while (t--) {
        solve();
    }
    return 0;
}

//here is 2nd method it not giving any error

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//const long MAXN=100;
typedef unsigned long long int ll;
ll fact[30];
void solve() {
    char s[22];
    scanf("%s", s);
    ll n;
    cin >> n;
    ll cnt[26] = {0}, len = strlen(s);
    // memset(cnt,0, sizeof(cnt));
    for (ll i = 0; i < len; i++)
        cnt[s[i] - 'a']++;

    ll sum = 0, k = 0;
    char out[len];
    for (ll i = 0; i < len; i++) {
        // cout<<s[i]<<endl;
        for (ll j = 0; j < 26; j++) {
            sum = fact[len - i - 1];
            if (cnt[j] > 0) {
                //  cout<<"in  j loop \n";
                for (ll x = 0; x < 26; x++) {
                    if (x == j)
                        sum /= fact[cnt[x] - 1];
                    else
                        sum /= fact[cnt[x]];
                    //cout<<x<<" "<<fact[cnt[x]]<<endl;
                }
                // cout<<sum<<" ";
                if (n > sum)
                    n -= sum;
                else {
                    out[k++] = (char) (j + 'a');
                    cnt[j]--;
                    //cout<<"in char adding\n";
                    break;
                }
            }
        }
    }
    out[k] = '\0';
    printf("%s\n", out);
}
int main() {
    fact[0] = fact[1] = 1;
    for (ll i = 2; i < 30; i++)
        fact[i] = (fact[i - 1] * i);
    long t;
    scanf("%lld",&t);
    while (t--) {
        solve();
    }
    return 0;
}

