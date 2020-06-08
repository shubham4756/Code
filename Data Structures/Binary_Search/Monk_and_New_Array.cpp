/*
Link:https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monk-and-new-array/description/?layout=old
Editorial:https://www.geeksforgeeks.org/minimum-difference-adjacent-elements-array-contain-elements-row-matrix/
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Md=1e9+7;
long int n,m;
long int mat[1001][1001];
long int find_ans(long int low,long int high,long int key,long int arr[]){
    long int mid=(low+high)/2;

    if(low<=high){
        if(arr[mid]<key) return find_ans(mid+1,high,key,arr);
        else return find_ans(low,mid-1,key,arr);
    }
    return low;
}
void solve() {
    cin >> n >> m;
    for (long int i = 0; i < n; i++) {
        for (long int j = 0; j < m; j++)
            cin >> mat[i][j];
        sort(mat[i],mat[i]+m);
    }

    long int ans=INT_MAX;
    for(long int i=0;i<n-1;i++){
        for(long int j=0;j<m;j++) {
            long int idx = find_ans(0, m - 1, mat[i][j], mat[i + 1]);
            ans = min(ans, abs(mat[i + 1][idx] - mat[i][j]));
            if (idx - 1 >= 0)
                ans = min(ans, abs(mat[i + 1][idx - 1] - mat[i][j]));
        }
    }
    cout<<ans<<endl;
}
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    long int t;
//    cin >> t;
//    while (t--)
        solve();
    return 0;
}
