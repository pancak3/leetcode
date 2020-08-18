class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int sLen = s.size();
        string ret (sLen, ' ');
        int pos, len = 0, tmp;
        bool goingDown;

        --numRows; pos = 0; tmp = numRows << 1;
        while (pos < sLen) {
            ret[len++] = s[pos];
            pos += tmp;
        }

        for (int i = 1; i < numRows; ++i) {
            pos = i;
            goingDown = true;
            while (pos < sLen) {
                ret[len++] = s[pos];
                if (goingDown)
                    pos += (numRows - i) << 1;
                else
                    pos += i << 1;
                goingDown = !goingDown;
            }
        }

        pos = numRows;
        while (pos < sLen) {
            ret[len++] = s[pos];
            pos += tmp;
        }

        return ret;
    }
};