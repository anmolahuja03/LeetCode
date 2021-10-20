class Solution {
public:
    bool isAnagram(string s, string t) {
        // Approach 1
        // T C : O(nlogn)
        // S C : O(1)
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         if(s == t) 
//             return true;
//         else
//             return false;
        
//         return true;
        
        
        
        // Approach 2
        // T C : O(n)
        // S C : O(1)
        int hash[26] = {0};
        
        for(int i = 0; i < s.length(); i++) {
            hash[s[i] - 'a']++;
        }   
        
        for(int i = 0; i < t.length(); i++) {
            hash[t[i] - 'a']--;
        }
        
        for(int i = 0; i < 26; i++) {
            if(hash[i] > 0 || hash[i] < 0) 
                return false;
        }
        return true;
    }
};