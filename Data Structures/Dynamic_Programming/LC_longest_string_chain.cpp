/*
Link:https://leetcode.com/problems/longest-string-chain/submissions/
editorial:https://leetcode.com/problems/longest-string-chain/discuss/638101/C%2B%2B-DP-solution-or-Got-96-time-100-memory
first sort by size
*/

class Solution {
public:
    
    bool check(string a,string b){
        if(a.size()+1!=b.size()){
           // cout<<a.size()+1<<" "<<b.size()<<"in first \n";
            return false;
        }
        int n=b.size();
        if(b.substr(1)==a)
            return true;
        if(b.substr(0,a.size())==a)
            return true;
        for(int i=1;i<n-1;i++){
            string s=b.substr(0,i)+b.substr(i+1);
           // cout<<s<<endl;
            if(s==a)
                return true;
        }
        return false;
    }
    bool mycomp(string a,string b){
        if(a.size()!=b.size())
            return a.size()<b.size();
        
        return false;
    }
    int longestStrChain(vector<string>& words) {
        
        vector<vector<pair<string,int> > > sortbylen(16);
        
        for(string &word:words){
            sortbylen[word.size()-1].push_back({word,1});
        }
        int ans=1;
        for(int i=sortbylen.size()-2;i>=0;i--){
            for(auto &pair1:sortbylen[i]){
                for(auto &pair2:sortbylen[i+1]){
                    if(check(pair1.first,pair2.first)){
                        pair1.second=max(pair1.second,pair2.second+1);
                        ans=max(ans,pair1.second);
                    }
                }
            }
        }
        return ans;
    }
};
