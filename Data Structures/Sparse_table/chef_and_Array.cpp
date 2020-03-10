/*
Link:https://www.codechef.com/problems/FRMQ
*/

//First solution  more efficient
#include<bits/stdc++.h>
using namespace std;
#define mx 114514
int table[17][mx];
int power[18],logs[mx];
int main()
{
    int n,m,x,y,low,high,len,lg;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&table[0][i]);
    }
    for(int i=0; i<=17; i++) power[i] = (1<<i);
    for(int i=1; i<=n; i++) logs[i] = log2(i);

    for(int j=1; power[j]<=n;j++){
        for(int i=0; i+power[j] <= n ; i++){
            table[j][i] = max(table[j-1][i] , table[j-1][ i+power[j-1]]);
        }
    }
    scanf("%d%d%d",&m,&x,&y);
    long ans = 0;
    low = x,high = y;
    if(low>high) swap(low,high);
    len = high-low+1;
    lg = logs[len];
    ans+=max(table[lg][low] , table[lg][ high-power[lg]+1 ]);
    for(int i=2; i<=m; i++){
        x+=7;
        if(x>=(n-1))x%=(n-1);
        y+=11;
        if(y>=n)y%=n;
        low = x,high = y;
        if(low>high) swap(low,high);
        len = high-low+1;
        lg = logs[len];
        ans+=max(table[lg][low], table[lg][ high-power[lg]+1 ]);
    }
    printf("%ld\n",ans);
    return 0;
}


//Second solution
#include<bits/stdc++.h>
using namespace std;
long int xx=0;
int n;
int looks[100005][18];
void preprocess(long int A[]) {
    for (int i = 0; i < n; i++) {
        looks[i][0] = i;
    }
    for (long int j = 1; (1 << j) <= n; j++) {
        for (long int i = 0; (i + (1 << j) - 1) < n; i++) {

            if (A[looks[i][j - 1]] > A[looks[i + (1 << (j - 1))][j - 1]]) {
                looks[i][j] = looks[i][j - 1];
            } else
                looks[i][j] = looks[i + (1 << (j - 1))][j - 1];
        }
    }
}
long int query(long int A[],long int l,long int r) {
    long int j = log2(r - l + 1);
    if (A[looks[l][j]] >= A[looks[r - (1 << j) + 1][j]])
        return A[looks[l][j]];
    else
        return A[looks[r - (1 << j) + 1][j]];
}
int main() {
    scanf("%d",&n);
    long int A[n];
    for (int i = 0; i < n; i++)
        scanf("%ld",&A[i]);
    long int m, x, y;
    preprocess(A);
    scanf("%ld",&m);
    scanf("%ld",&x);
    scanf("%ld",&y);
    while (m--) {
        xx += query(A, min(x, y), max(x, y));
        x = (x + 7) % (n - 1), y = (y + 11) % n;
    }
    printf("%ld\n",xx);
}
