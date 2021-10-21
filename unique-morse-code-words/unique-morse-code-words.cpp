class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        
        for(string word : words) {
            string ans = "";
            for(char c : word) {
                ans += codes[c - 'a'];
            }
            st.insert(ans);
        }
        return st.size();
    }
};