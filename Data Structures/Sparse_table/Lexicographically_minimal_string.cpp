/*
Link:https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/lexicographically-minimal-string-6edc1406/description/
*/


#include<bits/stdc++.h>
using namespace std;
long int n,m;
int a[100005];
int size[100005];
string sa,sb,sc;
void preprocess() {
    for (auto i = 'a'; i <= 'z'; i++) {
        a[i] = i;
        size[i] = 1;
    }
}
long int find(char x) {
    if (x != a[x])
        a[x] = find(a[x]);
    return a[x];
}
void makeunion(char x,char y) {
    long int xpre = find(x);
    long int ypre = find(y);
    if (xpre == ypre)
        return;
    if (size[xpre] >= size[ypre]) {
        a[ypre] = a[xpre];
        size[ypre] += size[xpre];
    } else {
        a[xpre] = a[ypre];
        size[xpre] += size[ypre];
    }
}
int main() {
    cin >> sa >> sb >> sc;
    n = sa.size();
    preprocess();
    for (long int i = 0; i < n; i++)
        makeunion(sa[i], sb[i]);
        
        //here array A hava disjoint if u print from 'a' to 'z' u can see
    vector<char> vec[27];
    for (auto i = 'a'; i <= 'z'; i++) {
        vec[a[i] - 'a'].push_back(i);
    }
     //finding minimum elemet from all set of char relations 
    char minn[27];
    for (auto i = 'a'; i <= 'z'; i++) {
        sort(vec[i - 'a'].begin(), vec[i - 'a'].end());
        if (vec[i - 'a'].size())
            minn[i - 'a'] = vec[i - 'a'][0];
        else
            minn[i - 'a'] = i;
    }
    for (int i = 0; i < sc.size(); i++) {
        long int c = find(sc[i]);
        cout << (char) minn[c - 'a'];
    }
    cout << endl;
    return 0;
}
