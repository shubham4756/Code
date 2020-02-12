/*
Link:https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/earthandthemeteorites-qualifier2/submissions/
for undertand go comment section
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    long int t;
    cin>>t;
    while(t--) {
        long int n,m,q;
        cin>>n>>m>>q;
        set<long int > sx,sy;
        long int x,y;
        sx.insert(1); sy.insert(1);
        sx.insert(n); sy.insert(m);
        for(long int i=0;i<q;i++)
        {
            cin>>x>>y;
            sx.insert(x);
            sy.insert(y);
        }
        vector<long int > vx,vy;
        long int minx=INT_MAX,maxx=INT_MIN,miny=INT_MAX,maxy=INT_MIN;
        for(auto it=sx.begin();it!=sx.end();it++)
           vx.push_back(*it);
        for(auto it=sy.begin();it!=sy.end();it++)
           vy.push_back(*it);

        for(long int i=0;i<vx.size()-1;i++)
        {
            if(vx[i+1]-vx[i]<minx)
                minx=vx[i+1]-vx[i];
            if(vx[i+1]-vx[i]>maxx)
                maxx=vx[i+1]-vx[i];
        }
        for(long int i=0;i<vy.size()-1;i++)
        {
            if(vy[i+1]-vy[i]<miny)
                miny=vy[i+1]-vy[i];
            if(vy[i+1]-vy[i]>maxy)
                maxy=vy[i+1]-vy[i];
        }
        cout<<(vx.size()-1)*(vy.size()-1)<<" "<<minx*miny<<" "<<maxx*maxy<<endl;
    }
    return 0;
}
