class Solution {
public:
    
    void helper(int index, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        
        if(target < 0 || candidates.size() == index)
            return;
        
        for(int i = index; i < candidates.size(); i++) {
            // Skipping duplicates
            if(i > index && candidates[i] == candidates[i - 1]) 
                continue;
            
            temp.push_back(candidates[i]);
            helper(i + 1, target - candidates[i], candidates, temp, res);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        
        helper(0, target, candidates, temp, res);
        return res;
    }
};