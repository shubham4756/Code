/*
Link:https://leetcode.com/problems/all-possible-full-binary-trees/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map < int, vector<TreeNode*> > mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode* > res;
        if(mp[n].size()!=0) return mp[n];
        if(n==1) {
            res.push_back(new TreeNode(0));
        } else {
            for(int i=1;i<n;i+=2) {
                int l=i,r=n-l-1;
                for(TreeNode* left: allPossibleFBT(l)) {
                    for(TreeNode* right: allPossibleFBT(r)) {
                        TreeNode * root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        res.push_back(root);
                    }
                }
             }
        }
        mp[n]=res;
        return res;
    }
};
