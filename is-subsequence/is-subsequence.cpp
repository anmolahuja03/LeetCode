class Solution {
public:
    
    int LCS(string& text1, string& text2, int x, int y) {
        int dp[x + 1][y + 1];
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i < x + 1; i++) {
            for(int j = 0; j < y + 1; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < x + 1; i++) {
            for(int j = 1; j < y + 1; j++) {
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[x][y];
    }
    
    
    bool isSubsequence(string s, string t) {
        /*
        // Approach 1 - Two Pointers
        
        int i = 0, j = 0;
        
        while(i < s.length() && j < t.length()) {
            if(s[i] == t[j]) {
                i++;
                j++;
            }
            else if(s[i] != t[j]) {
                j++;
            }
        }
        
        if(i == s.length()) 
            return true;
        return false;        
        */
        
        // Approach 2 - DP
        
        int n1 = s.length();
        int n2 = t.length();
        
        if(LCS(s, t, n1, n2) == n1)
            return true;
        return false;
    }
};