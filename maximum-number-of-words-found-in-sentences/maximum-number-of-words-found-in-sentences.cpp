class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = INT_MIN;
        for(auto i = 0; i < sentences.size(); i++) {
            int cnt = 0;
            for(auto j = 0; j < sentences[i].size(); j++) {
                if(sentences[i][j] == ' ')
                    cnt++;
            }
            cnt += 1;
            res = max(res, cnt);
        }
        return res;
    }
};