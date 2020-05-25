/*
Link:https://leetcode.com/problems/knight-probability-in-chessboard/
*/

class Solution {
const double tot=8.0;
public:
    double dfs(int N, int K, int r, int c,  vector<vector<vector<double>>>& dp) {
        int dx[]={-2,-2,1,-1,2,2,1,-1};
        int dy[]={1,-1,2,2,1,-1,-2,-2};
        if (r < 0 || c < 0 || r >= N || c >= N)
            return 0;
        if (K == 0) return 1;
        if (dp[K][r][c] != -1) 
            return dp[K][r][c];
        
        double moves =  0;
        for(int i=0;i<8;i++){
            moves+=dfs(N,K-1,r+dx[i],c+dy[i],dp);
        }
        moves /= tot;
        dp[K][r][c] = moves;
        return dp[K][r][c];
    }
double knightProbability(int N, int K, int r, int c) {
     
    vector<vector<vector<double>>>dp(K+1, vector<vector<double>>(N+1, vector<double>(N+1, -1)));
        return dfs(N, K, r, c, dp);
}
};
