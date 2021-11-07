class Solution {
public:
    int dp[1001][1001];
    
    int LCS(string& text1, string& text2, int x, int y) {
        if(x == 0 || y == 0)
            return 0;
        if(dp[x][y] != -1)
            return dp[x][y];
        
        if(text1[x - 1] == text2[y - 1])
            return dp[x][y] = 1 + LCS(text1, text2, x - 1, y - 1);
        else
            return dp[x][y] = max(LCS(text1, text2, x - 1, y), LCS(text1, text2, x, y - 1));
    }
    
    
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        string temp = s;
        reverse(temp.begin(), temp.end());
        return LCS(s, temp, s.length(), temp.length());
    }
};