/*
link:https://leetcode.com/problems/unique-binary-search-trees/
it's based on catlan number;
*/
class Solution {
public:
    unsigned long long ncr(int n, int r)
    {
        unsigned long long res=1;
        for(int i=1;i<=r;i++)
        {
            res= res*(n-i+1);
            res = res/i;
            
        }
        return res;
    }
    int numTrees(int n) {
        return ncr(2*n,n)/(n+1);
    }
};
