class Solution {
public:
    vector<vector<int>> res;
    
    void helper(vector<int>& nums, int index, vector<int> temp) {
        // Base Case
        if(index == nums.size()) {
            res.push_back(temp);
            return;
        }
        
        // Excluding an element
        helper(nums, index + 1, temp);
        
        // Including an element
        temp.push_back(nums[index]);
        helper(nums, index + 1, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(nums, 0, temp);
        return res;
    }
};