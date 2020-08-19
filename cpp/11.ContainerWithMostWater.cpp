#include "vector"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        unsigned int left = 0, right = height.size() - 1, area, maxContain = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                area = height[left] * ( right - left);
                if (area > maxContain) maxContain = area;
                while (height[left++] >= height[left] && left < right );

            } else {
                area = height[right] * ( right - left);
                if (area > maxContain) maxContain = area;
                while (height[right--] >= height[right] && left < right);
            }
        }
        return (int) maxContain;
    }
};