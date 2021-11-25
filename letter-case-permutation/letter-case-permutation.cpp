class Solution {
public:
    void helper(string& s, vector<string>& res, string temp, int idx) {
        // Base Case
        if(idx == s.size()) {
            res.push_back(temp);
            return;
        }
        
        // When there is an integer in a string
        if(isdigit(s[idx]))
            helper(s, res, temp + s[idx], idx + 1);
        // When there is an alphabet
        else if(isalpha(s[idx])) {
            // Changing alphabet to uppercase
            helper(s, res, temp + (char)(toupper(s[idx])), idx + 1);
            // Changing alphabet to lowercase
            helper(s, res, temp + (char)(tolower(s[idx])), idx + 1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string temp = "";
        helper(s, res, "", 0);
        return res;
    }
};