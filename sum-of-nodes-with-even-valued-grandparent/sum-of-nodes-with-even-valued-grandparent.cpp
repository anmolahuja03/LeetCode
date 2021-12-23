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
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        // Base case
        if(!root)
            return 0;
        if(root->val % 2 == 0) {
            if(root->left && root->left->left)
                sum += root->left->left->val;
            if(root->left && root->left->right)
                sum += root->left->right->val;
            if(root->right && root->right->left)
                sum += root->right->left->val;
            if(root->right && root->right->right)
                sum += root->right->right->val;
        }
        
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        return sum;
    }
};