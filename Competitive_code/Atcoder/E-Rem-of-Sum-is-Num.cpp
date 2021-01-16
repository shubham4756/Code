/*
Link: https://atcoder.jp/contests/abc146/tasks/abc146_e
Explanation: Let’s define a sequence {Sn} such that Si = A1 + A2 + · · · Ai . Let S0 = 0.
Then, the condition that a contiguous subsequence Ai+1, . . . , Aj should meet can be represented
like
                     (Sj − Si)%K = j − i.
This equation can be transformed to the following equivalent conditions:
                (Sj − j)%K = (Si − i)%K and j − i < K
Therefore, for each j (1 ≤ j ≤ N) you should count the number of j − K < i < j such that
                      (Sj − j)%K = (Si − i)%K.
If you search them this naively one by one it won’t finish in time, but for j the segment needed
to be searched is (j − K, j), and for j + 1, it is (j − K + 1, j + 1), and these differs only by one
elements at the leftmost and rightmost, so in order to search for j + 1-th after searching for j-th
element, you only have to discard the leftmost element and add the rightmost element.
Operations of discarding or adding can be performed quickly by managing the number of Si −i’s
by using associative arrays (such as map in C++ or dict in Python).
The total time complexity is about O(N log K).

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";

template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int  MOD=1000000007;
const int N=100005;

ll n,k,a[2*N],pre[2*N]={0},tot=0;
map<ll,ll> mp;

void solve() {
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]--;
        a[i] %= k;
        pre[i] = pre[i - 1] + a[i];
        pre[i] %= k;
    }
    mp[pre[0]] = 1;
    for (ll i = 1; i <= n; i++) {
        if (i >= k) mp[pre[i - k]]--;
        tot += mp[pre[i]];
        mp[pre[i]]++;
    }
    cout << tot << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
//    cin>>t;                     // DON'T FORGET IT. ^^^
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}
