class Solution {
public:
    void helper(int k, int n, vector<vector<int>>& res, vector<int>& curr, int idx) {
        if(curr.size() == k && n == 0) {
            res.push_back(curr);
            return;
        }
        
        if(n < 0 || curr.size() == k)
            return;
        
        for(int i = idx; i <= 9; i++) {
            curr.push_back(i);
            helper(k, n - i, res, curr, i + 1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        
        helper(k, n, res, curr, 1);
        
        return res;
    }
};