/*
https://leetcode.com/problems/filling-bookcase-shelves/submissions/
*/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n=books.size();
        vector<int> dp(n);
        
        for(int i=0;i<n;i++){
            int min_height=INT_MAX,height=0,width=0;
        
            for(int j=i;j>=0;j--){
                width+=books[j][0];
                height=max(height,books[j][1]);
                if(width>shelf_width)
                     break;
                int shelf_height=j==0 ? height : dp[j-1]+height;
                min_height=min(shelf_height,min_height);
                
            }
            dp[i]=min_height;
        }
        return dp[n-1];
    }
};
