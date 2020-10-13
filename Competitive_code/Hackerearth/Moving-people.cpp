/*
Link : https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/mind-flayer-returns-68bb7306/description/?layout=old
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

const int  MOD=1000000007;
const int N=200010;

void solve(){
	long n,m,q;
	cin>>n>>m>>q;
	char a[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	long pre[n+1][m+1];
	memset(pre,0,sizeof(pre));
	pre[1][1]=(a[1][1]=='1');
	for(int i=2;i<=n;i++){
		pre[i][1]=pre[i-1][1]+(a[i][1]=='1');
	}
	for(int j=2;j<=m;j++){
		pre[1][j]=pre[1][j-1]+(a[1][j]=='1');
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(a[i][j]=='1');
		}
	}
	long stX=1,stY=1,edX=n,edY=m;
	long minX=1,minY=1,maxX=n,maxY=m;
	while(q--){
		long ty; cin>>ty;
		if(ty==2){
			if(maxX<minX || maxY<minY){
				cout<<"0\n";
				continue;
			}
			long ans=pre[maxX][maxY]+pre[minX-1][minY-1]-pre[minX-1][maxY]-pre[maxX][minY-1];
			cout<<ans<<endl;
		} else {
			long x,y;
			cin>>y>>x;
			stX+=x; edX+=x;
			edY+=y; stY+=y;
			maxX=min(maxX,edX);
			minX=max(minX,stX);
			maxY=min(maxY,edY);	
		    minY=max(minY,stY);	
		} 
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    // cin>>t;                     // DON'T FORGET IT. ^^^
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    cerr << "Time : " << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}
