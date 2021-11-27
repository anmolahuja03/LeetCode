class Solution {
public:
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& currSubset, int idx) {
        ans.push_back(currSubset);      
        
        for(int i = idx; i < nums.size(); i++) { 
            // To check duplicates
            if(i > idx && nums[i] == nums[i - 1]) 
                continue;      
            // Store
            currSubset.push_back(nums[i]); 
            // Recursive Call
            helper(nums, ans, currSubset, i + 1); 
            //Backtrack
            currSubset.pop_back();        
        }
    }  
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Inorder to make sure that 
        // duplicates are adjacent
        sort(nums.begin(), nums.end());    
        vector<vector<int>> ans;    
        vector<int> currSubset;           
        helper(nums, ans, currSubset, 0);       
        return ans;
    }
};