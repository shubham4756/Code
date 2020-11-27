/*
Link: https://codeforces.com/contest/1144/problem/E
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

vector<int> Get(string s) {
    vector<int> v(s.size() + 1);
    for (int i = 0; i < s.size(); i++) {
        v[i + 1] = (s[i] - 'a');
    }
    return v;
}

void solve() {
    long n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> a = Get(s), b = Get(t);
    for (long i = n; i >= 0; i--) {
        a[i] += b[i];
        if (i) {
            a[i - 1] += a[i] / 26;
            a[i] %= 26;
        }
    }
    for (long i = 0; i <= n; i++) {
        long rem = a[i] % 2;
        a[i] /= 2;
        if (i + 1 <= n) {
            a[i + 1] += rem * 26;
        }
    }
    for (long i = 1; i <= n; i++) {
        cout << (char) (a[i] + 'a');
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
//     cin>>t;                     // DON'T FORGET IT. ^^^
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}
