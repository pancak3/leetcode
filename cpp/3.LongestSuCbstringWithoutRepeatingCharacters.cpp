class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned int n = s.length(), ans = 0, diff;
        unsigned int index[128] = {0};

        for(unsigned int i = 0, j = 0; j < n; j++){
            if(index[s[j]] > i) i = index[s[j]];
            diff = j - i + 1;
            if(diff > ans) ans = diff;
            index[s[j]] = j + 1;
        }

        return ans;
    }
};t