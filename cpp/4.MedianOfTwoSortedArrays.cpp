class Solution {

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

        vector<int>& left = nums1.size() < nums2.size() ? nums1 : nums2;
        vector<int>& right = nums1.size() < nums2.size() ? nums2 : nums1;

        int leftLen = left.size(), rightLen = right.size();
        int low = 0, high = leftLen, mid = (leftLen + rightLen + 1) >> 1;

        int i, j, a, b, c, d;

        while(low <= high){
            i = (low + high + 1)  >> 1;
            j = mid - i;

            a = i == 0 ? INT_MIN : left[i - 1];
            b = i == leftLen ? INT_MAX : left[i];
            c = j == 0 ? INT_MIN : right[j - 1];
            d = j == rightLen ? INT_MAX : right[j];

            if (a <= d && c <= b) {
                if (((leftLen + rightLen) & 1) == 1)
                    return a > c ? a : c;
                else
                    return ((a > c ? a : c) + (b < d ? b : d)) / 2.0;
            } else if ( a > d)
                high -= (high - low + 1)  >> 1;
            else
                low += (high - low + 1) >> 1;

        }
        return 0.0;

    }
};