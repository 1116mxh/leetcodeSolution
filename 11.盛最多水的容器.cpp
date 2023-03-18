/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size()-1,left = 0;
        int h = min(height[right],height[left]);
        int result = h*(right-left);
        for(;left<right;){
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
            h = min(height[right],height[left]);
            result = max(result,h*(right-left));
        }
        
        return result;

    }
};
// @lc code=end

