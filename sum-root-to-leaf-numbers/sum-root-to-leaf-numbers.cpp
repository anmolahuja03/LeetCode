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
    void helper(TreeNode* root, int& res, int temp) {
        if(!root)
            return;
        temp = temp * 10 + root->val;
        if(!root->left && !root->right)
            res += temp;
        else {
            helper(root->right, res, temp);
            helper(root->left, res, temp);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int res = 0;
        helper(root, res, 0);
        return res;
    }
};