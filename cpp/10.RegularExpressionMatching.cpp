class Solution {
public:
    bool isMatch(string s, string p) {

        int sLen = s.size(), pLen = p.size();
        bool dp[sLen + 1][pLen + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for (int j = 1; j <= pLen; ++j)
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];

        for (int i = 1; i <= sLen; ++i) {
            for (int j = 1; j <= pLen; ++j) {
                if ( s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
            }
        }

        return dp[sLen][pLen];
    }
};