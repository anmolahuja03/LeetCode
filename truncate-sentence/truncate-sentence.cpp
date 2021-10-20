class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0;
        string ans = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                cnt++;
            }
            if(cnt < k) {
                ans += s[i];
            }
        }
        return ans;
    }
};