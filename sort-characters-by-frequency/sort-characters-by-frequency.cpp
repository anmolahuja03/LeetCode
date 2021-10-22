class Solution {
public:
    static bool cmp(pair<char,int>& x, pair<char,int>& y) {
        return x.second > y.second;
    }
    
    string frequencySort(string s) {
        string res = "";
        unordered_map<char,int> M;
        vector<pair<char,int>> temp;
        
        for(auto ch : s) {
            M[ch]++;
        }
        
        for(auto it : M) {
            temp.push_back({it.first, it.second});
        }
        
        sort(temp.begin(), temp.end(), cmp);
        
        for(auto x : temp) {
            for(int i = 0; i < x.second; i++) {
                res += x.first;
            }
        }
        return res;
    }
};