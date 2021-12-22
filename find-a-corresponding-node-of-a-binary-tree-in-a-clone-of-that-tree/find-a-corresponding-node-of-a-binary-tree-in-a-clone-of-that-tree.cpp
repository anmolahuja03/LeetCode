/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* cloned, TreeNode* target) {
        if(!cloned)
            return NULL;
        if(cloned->val == target->val)
            return cloned;
        TreeNode* left = helper(cloned->left, target);
        TreeNode* right = helper(cloned->right, target);
        if(left)
            return left;
        if(right)
            return right;
        return NULL;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) { 
        return helper(cloned, target);
    }
};