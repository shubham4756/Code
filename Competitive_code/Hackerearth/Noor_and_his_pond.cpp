/*
Link:https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/noor-and-his-pond-760eabe0/
explation link:https://www.youtube.com/watch?v=Ndc1EMq25R0&feature=youtu.be&t=1m17s
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    long int t;
    cin>>t;
    while(t--) {
        long int n,x,y;
        cin >> n;
        vector<pair<long int,long int> > v;
        for (long int i = 0; i < n; i++){
            cin>>x>>y;
            v.push_back(make_pair(y,x));
        }
        sort(v.begin(),v.end());
        multiset<long int > m;
        long int ans=m.size();
        for(auto e: v)
        {
            m.insert(e.second);
            m.erase(m.begin(),m.upper_bound(e.first));
            ans=max(ans,(long int)m.size());
        }
        cout<<ans<<endl;
    }
    return 0;
}
