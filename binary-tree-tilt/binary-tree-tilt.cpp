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
    int helper(TreeNode* root, int& final_sum) {
        if(!root)
            return 0;

        int left_sum = helper(root->left, final_sum);
        int right_sum = helper(root->right, final_sum);
        int local_tilt = abs(left_sum - right_sum);
        final_sum += local_tilt;
        return left_sum + right_sum + root->val;
    }
    
    int findTilt(TreeNode* root) {
        int final_sum = 0;
        helper(root, final_sum);
        return final_sum;
    }
};