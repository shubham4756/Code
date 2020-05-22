/*
Link:https://leetcode.com/problems/largest-sum-of-averages/
Editorial:https://leetcode.com/problems/largest-sum-of-averages/discuss/561245/top-down-and-bottom-up-with-detail-explanation
Solution:https://leetcode.com/problems/largest-sum-of-averages/discuss/641757/Simple-C%2B%2B-solution
Solution:https://leetcode.com/problems/largest-sum-of-averages/discuss/598668/C%2B%2B-easy-to-understand-DP
*/

class Solution {
public:
    double memo[200][200];
    double largestSumOfAverages(vector<int>& A, int K) {
        memset(memo, 0, sizeof(memo));
        int N = A.size();
        double cur = 0;
        for (int i = 0; i < N; ++i) {
            cur += A[i];
            memo[i + 1][1] = cur / (i + 1);
        }
        return search(N, K, A);
    }

    double search(int n, int k, vector<int>& A) {
        if (memo[n][k] > 0) return memo[n][k];
        if (n < k) return 0; 
        double cur = 0;
        for (int i = n - 1; i > 0; --i) {
            cur += A[i];
            memo[n][k] = max(memo[n][k], search(i, k - 1, A) + cur / (n - i));
        }
        return memo[n][k];
    }
};
