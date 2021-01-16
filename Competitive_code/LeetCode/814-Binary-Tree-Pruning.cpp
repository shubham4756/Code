/*
Link: https://leetcode.com/problems/binary-tree-pruning/
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
    TreeNode* pruneTree(TreeNode* root) {
        if(containOne(root))
            return root;
        else
            return NULL;
    }
    bool containOne(TreeNode* root) {
        if(root==NULL) return false;
        bool a1=containOne(root->left);
        bool a2=containOne(root->right);
        if(!a1) root->left=NULL;
        if(!a2) root->right=NULL;
        return root->val == 1 || a1 || 
    }
};
