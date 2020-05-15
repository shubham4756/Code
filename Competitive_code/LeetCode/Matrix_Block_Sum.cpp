/*
Link:https://leetcode.com/problems/matrix-block-sum/submissions/
Link:https://leetcode.com/problems/matrix-block-sum/discuss/608319/C%2B%2B2D-prefix-sum
*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int> >  ans(mat.size());
        vector<vector<int> > pre(mat.size()+1);
        int n_row=mat.size();
        int n_col=mat[0].size();
        
        pre[0]=vector<int>(n_col+1);
        
        for(int i=1;i<=n_row;i++){
            pre[i]=vector<int>(n_col+1);
            for(int j=1;j<=n_col;j++){
                pre[i][j]=pre[i-1][j]+pre[i][j-1]+mat[i-1][j-1]-pre[i-1][j-1];
            }
        }
        
        for(int i=0;i<n_row;i++){
            ans[i]=vector<int>(n_col);
            
            for(int j=0;j<n_col;j++){
                int row_min=max(0,i-K);
                int col_min=max(0,j-K);
                int row_max=min(n_row-1,i+K);
                int col_max=min(n_col-1,j+K);
                ans[i][j]=pre[row_max+1][col_max+1]-pre[row_min][col_max+1]-pre[row_max+1][col_min]+pre[row_min][col_min];
                
            }
        }
        return ans;
    }
};
