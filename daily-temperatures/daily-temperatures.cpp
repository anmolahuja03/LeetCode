class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        Approach 1 - Brute
        T C : O(n^2)
        S C : O(1)
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++) {
            for(int j = i + 1; j < temperatures.size(); j++) {
                if(temperatures[j] > temperatures[i]) {
                    res[i] = (j - i);
                    break;
                }
            }
        }
        return res;
        */
        
        
        // Approach 2 - Stack
        // T C : O(n)
        // S C : O(n)
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        
        for(int i = temperatures.size() - 1; i >= 0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()] )
                st.pop();
            if(!st.empty())
                res[i] = st.top() - i;
            st.push(i);
        }
        return res;
    }
};