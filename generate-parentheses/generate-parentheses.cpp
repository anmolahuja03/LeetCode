class Solution {
public:
    // T C : O(2^n)
    // S C : O(n)
    
    void helper(vector<string>& res, int n, int open, int close, string ans) {
        // Base Case
        if(open == n && close == n) {
            res.push_back(ans);
            return;
        }
        
        if(n > open) {
            helper(res, n, open + 1, close, ans + "(");
        }
        if(open > close) {
            helper(res, n, open, close + 1, ans + ")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = 0, close = 0;
        helper(res, n, open, close, "");
        return res;
    }
};