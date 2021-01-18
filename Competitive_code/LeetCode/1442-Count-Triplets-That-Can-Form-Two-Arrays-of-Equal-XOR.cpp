/*
Link: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
Explanation: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/discuss/623747/JavaC%2B%2BPython-One-Pass-O(N4)-to-O(N)
*/

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size(), res = 0, prefix = 0;
        unordered_map<int, int> count = {{0, 1}}, total;
        for (int i = 0; i < n; ++i) {
            prefix ^= A[i];
            res += count[prefix]++ * i - total[prefix];
            total[prefix] += i + 1;
        }
        return res;
    }
};
