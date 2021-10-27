class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        unordered_map<char, int> M;
        for(auto it : allowed) {
            M[it]++;
        }
        
        for(auto s : words) {
            int flag = true;
            for(char ch : s) {
                if(!M[ch]) {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                cnt++;
        }
        return cnt;
    }
};