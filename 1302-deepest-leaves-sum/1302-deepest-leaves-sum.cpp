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
    int deepestLeavesSum(TreeNode* root) {
        int level_sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            level_sum = 0;
            int queue_size = q.size();
            if(queue_size) {
                for(int i = 0; i < queue_size; i++) {
                    auto x = q.front();
                    level_sum += x->val;
                    q.pop();
                    if(x->left)
                        q.push(x->left);
                    if(x->right)
                        q.push(x->right);
                }
            }
        }
        return level_sum;
    }
};