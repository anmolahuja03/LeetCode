class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        if(l == r)
            return true;
        while(l < r) {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    
    void helper(vector<vector<string>>& res, vector<string>& curr, string s) {
        // Base Case
        if(s.size() == 0)
            res.push_back(curr);
        
        for(int i = 0; i < s.size(); i++) {
            string check = s.substr(0, i + 1);
            if(isPalindrome(check)) {
                curr.push_back(check);
                helper(res, curr, s.substr(i + 1));
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        helper(res, curr, s);
        return res;
    }
};