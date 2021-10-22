class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        int idx = 0;
        while(idx < s.length()) {
            if(idx < s.length() - 2 && s[idx + 2] == '#') {
                res += (char) ((s[idx] - '0') * 10 + (s[idx + 1] - '0') + 96);
                idx += 3;
            }
            else {
                res += (char) (s[idx] + 48);
                idx++;
            }
        }
        return res;
    }
};