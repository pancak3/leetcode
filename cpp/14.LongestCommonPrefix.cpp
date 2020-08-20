class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int nStrs = strs.size();
        if (nStrs == 0) return "";
        if (nStrs == 1) return strs[0];
        int sLen = strs[0].size();
        if (sLen == 0) return "";

        string ret = "";
        int j = 0 ;

        while(true){
            for (int i = 1; i < nStrs; ++i) {
                if (j >= sLen || j >= strs[i].size() || strs[0][j] != strs[i][j])
                    return ret;
            }
            ret.push_back(strs[0][j]);
            ++j;
        }

        return ret;

    }
};