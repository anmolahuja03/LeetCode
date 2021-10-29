class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int half = arr.size()/2;
        unordered_map<int, int> M;
        vector<int> temp;
        int res = 0;
        
        for(auto x : arr) {
            M[x]++;
        }
        
        for(auto x : M) {
            temp.push_back(x.second);
        }
        
        int i = 0;
        sort(temp.begin(), temp.end(), greater<int>());
        
        while(n > half) {
            res++;
            n -= temp[i++];
        }
        return res;
    }
};