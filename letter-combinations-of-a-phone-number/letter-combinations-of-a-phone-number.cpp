class Solution {
public:
    vector<string> res;
    vector<string> options = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void backtrack(string digits, int index, string ans) {
        // Base Case
        if(index == digits.length()) {
            res.push_back(ans);
            return;
        }
        
        string temp = options[digits[index] - '0'];
        
        for(int i = 0; i < temp.length(); i++) {
            backtrack(digits, index + 1, ans + temp[i]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) 
            return res;
        
        string ans = "";
        backtrack(digits, 0, ans);
        
        return res;
    }
};