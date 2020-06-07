/*
Link:https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/will-shivam-make-it/?layout=old
Editorial:https://stackoverflow.com/questions/59311842/how-to-get-a-substring-by-deleting-minimum-number-of-characters
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Md=1e9+7;
int xx;
bool check(string s1,string s2) {
    xx = 0;
    bool ff = false;
    if (s2.empty())
        return false;
    int first = 0;
    while ((first = s1.find(s2[0], first)) != string::npos) {
        int numdel = 0;
        bool isSub = true;
        int next = first + 1;
        for (int j = 1; j < s2.size(); j++) {
            int found = s1.find(s2[j], next);
            if (found == string::npos) {
                isSub = false;
                break;
            }
            numdel += (found - next);
            next = found + 1;
        }
        if (isSub) {
            if (ff) {
                if (numdel < xx)
                    xx = numdel;
            } else {
                ff = true;
                xx = numdel;
            }
        }
        first++;
    }
    return ff;
}
void solve() {
    string s1, s2;
    cin >> s1;
    getchar();
    cin >> s2;
    if (check(s1, s2))
        cout << "YES " << xx << endl;
    else
        cout << "NO\n";

}
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    long int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
