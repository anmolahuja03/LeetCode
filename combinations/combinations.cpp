class Solution {
public:
    // T C : O(2^n)
    // S C : O(n)
    
    void helper(int n, int k, vector<int>& temp, vector<vector<int>>& ans, int index) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        
        for(int j = index; j <= n; j++) {
            temp.push_back(j);
            helper(n, k, temp, ans, j + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        helper(n, k, temp, ans, 1);
        return ans;
    }
};