/*
Link:https://leetcode.com/problems/palindromic-substrings/submissions/
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),ans=n;
        vector<vector<bool> > palin(n,vector<bool>(n,true));
        for(int j=1;j<n;j++){
            for(int i=0;i<n-j;i++){
                if(s[i]==s[i+j] && palin[i+1][i+j-1]){
                    palin[i][i+j]=true;
                    ans++;
                }
                else{
                    palin[i][i+j]=false;
                }
            }
        }
        return ans;
    }
};

/*
For find longest palindrom substring
Link:https://leetcode.com/problems/longest-palindromic-substring/submissions/
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),sz=0;
        int idx=0;
        vector<vector<bool> > palin(n,vector<bool>(n,true));
        for(int j=1;j<n;j++){
            for(int i=0;i<n-j;i++){
                if(s[i]==s[i+j] && palin[i+1][i+j-1]){
                   // cout<<i<<" "<<j<<" "<<i+j<<" "<<idx<<" "<<sz<<endl;
                    palin[i][i+j]=true;
                    if(sz<=j){
                      idx=i;
                      sz=j;
                    }
                }
                else{
                    palin[i][i+j]=false;
                }
            }
        }
        return s.substr(idx,sz+1);
    }
};
