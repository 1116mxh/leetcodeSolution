/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <=1 ) return;
        int start = 0;
        // 找到最后一个小于下一个数的位置
        int end = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i < nums.size()-1 && nums[i] < nums[i+1]){
                start = i;
                end = i+1;
                continue;
            }
            if(nums[end] > nums[i] && nums[i] > nums[start]){
                end = i;
            }
        }
        if(end == start && end == 0){
            sort(nums.begin(),nums.end());
            return;
        }

        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;

        sort(nums.begin()+start+1,nums.end());
        
        return;       
    }
};
// @lc code=end

