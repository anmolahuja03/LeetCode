class Solution {
public:
    int longestPalindrome(string s) {
        int cnt = 0;
        unordered_map<char, int> M;
        bool flag = false;
        
        for(int i = 0; i < s.length(); i++) {
            M[s[i]]++;
        }
        
        for(auto it : M) {
            if(it.second % 2 == 0) 
                cnt += it.second;
            else if(it.second % 2 != 0) {
                flag = true;
                int temp = it.second - 1;
                cnt += temp;
            }
        }
        if(flag)
            cnt += 1;
        return cnt;
    }
};