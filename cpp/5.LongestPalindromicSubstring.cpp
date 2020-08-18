class Solution {
public:
    string longestPalindrome(string& s) {
        int sLen = s.size();
        if (sLen < 2) return s;

        int left, right, start = 0, maxLen = 1, tmpLen;

        for (int i = 0; i< sLen; ){
            if (sLen - i < (maxLen >> 1)) break;
            left = i; right = i;

            while ( s[right] == s[right + 1])
                ++right;
            i = right + 1;

            while (left > 0 && right + 1 < sLen && s[left - 1] == s[right + 1]) {
                --left; ++right;
            }

            tmpLen = right - left + 1;

            if (tmpLen > maxLen) {
                maxLen = tmpLen;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};