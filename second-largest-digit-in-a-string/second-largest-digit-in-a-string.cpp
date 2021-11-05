class Solution {
public:
    int secondHighest(string s) {
        vector<int> res;
        
        for(int i = 0; i < s.length(); i++) {
            if(!isalpha(s[i]))
                res.push_back(s[i] - '0');
        }
        
        // for(auto x : res) {
        //     cout << x << " ";
        // }
        
        sort(res.begin(), res.end());
        
        for(int i = res.size() - 2; i >= 0; i--) {
            if(res[i] != res[res.size() - 1])
                return res[i];
        }
        
        return -1;
    }
};