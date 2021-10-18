class Solution {
public:
    // Approaches : a) Iterative 
    //              b) Rec + Backtracking
    //              c) Queue
    
    
    // c) Recursive Approach
    // T C : O(4^n)
    // S C : O(n)
    vector<string> res;
    vector<string> options = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void helper(string digits, int index, string ans) {
        // Base Case
        if(index == digits.length()) {
            res.push_back(ans);
            return;
        }
        
        string temp = options[digits[index] - '0'];
        
        for(int i = 0; i < temp.length(); i++) {
            helper(digits, index + 1, ans + temp[i]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) 
            return res;
        
        string ans = "";
        helper(digits, 0, ans);
        
        return res;
    }
};