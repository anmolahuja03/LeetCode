/*
class Solution {
public:
        T C : O(n)
        S C : O(1)

    bool backspaceCompare(string s, string t) {

        int i = 0, j = 0;
        string temp1 = "", temp2 = "";
        
        while(s[i] != '\0') {
            if(isalpha(s[i]))
                temp1 += s[i];
            else {
                if(!temp1.empty())
                temp1.pop_back();
            }
            i++;
        }
        

        while(t[j] != '\0') {
            if(isalpha(t[j])) 
                temp2 += t[j];
            else {
                if(!temp2.empty())
                temp2.pop_back();
            }
            j++;
        }
        
        if(temp1 == temp2)
            return true;
        else
            return false;
    }
};
*/


//-------------------------------------------------------------------------


class Solution {
public:
       // T C : O(n)
       // S C : O(n)
    
    string helper(string s) {
        string res = "";
        stack<char> st;
        
        for(auto c : s) {
            if(c != '#')
                st.push(c);
            else if(!st.empty())
                st.pop();
        }
        
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
    
    bool backspaceCompare(string s, string t) {
        if(helper(s) == helper(t))
            return true;
        else
            return false;
    }
};