class Solution {
public:
    // T C : O(n! * n)
    // S C : O(n)
    vector<vector<int>> res;
    
    void helper(vector<int>& nums, int index) {
        // Base Case
        if(index == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        
        for(int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);
            helper(nums, index + 1);
            swap(nums[index], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return res;
    }
};