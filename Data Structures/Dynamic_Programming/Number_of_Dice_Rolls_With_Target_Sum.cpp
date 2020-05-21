/*
Link:https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
recoursion solution:https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/discuss/636012/DP-C%2B%2B-solution
*/

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        //no of dices //no u get
        int dp[d+1][target+1];
        int Mod=1000000007;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=d;i++){
            for(int j=1;j<=target;j++){
                for(int k=1;k<=f;k++){
                    if(j>=k)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-k])%Mod;
                }
            }
        }
        return dp[d][target];
    }
};
