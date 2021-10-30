class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> res;
        
        for(int i = 0; i < word.size(); i++) {
            if(isalpha(word[i]))
                word[i] = ' ';
        }
        
        
        for(int i = 0; i < word.size(); i++) {
            if(isdigit(word[i]) && word[i] != ' ') {
			    string temp = "";
                while(word[i] == '0')
                    i++;
                while(isdigit(word[i])) {
                    temp += word[i];
                    i++;
                }
                res.insert(temp);
            }
        }
        return res.size();
    }
};
