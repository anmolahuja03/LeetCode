class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper_count = 0;
        int lower_count = 0;
        
        for(int i = 0; i < word.length(); i++) {
            if(islower(word[i]))
                lower_count++;
            else
                upper_count++;
        }
        
        if(lower_count == word.length() || upper_count == word.length()) 
            return true;
        
        if(upper_count == 1 && isupper(word[0]))
            return true;
        
        return false;
    }
};