class Solution {
public:
    string reversePrefix(string word, char ch) {
        int temp = -1;
        int i = 0;
        
        while(i < word.size()) {
            if(word[i] == ch) {
                temp = i;
                break;
            }
            i++;
        }
    
        if(temp != -1)
            reverse(word.begin(), word.begin() + temp + 1);
        
        return word;
    }
};