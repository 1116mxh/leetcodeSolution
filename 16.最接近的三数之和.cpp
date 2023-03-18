/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int deff = INT_MAX;
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i]==nums[i-1]){
                continue;
            }
            int temp = target - nums[i];
            int left = i+1;
            int right = nums.size()-1;
            for(;left<right;){
                int tempdeff = temp - nums[left] - nums[right];
                if(deff > abs(tempdeff)){
                    deff = abs(tempdeff);
                    result = nums[i]+nums[left]+nums[right];
                }
                if(tempdeff < 0){
                    right--;
                    while(left<right && nums[right] == nums[right+1]){
                        right--;
                    }
                }else{
                    left++;
                    while(left<right && nums[left] == nums[left-1]){
                        left++;
                    }
                }
            }   
        }

        return result;

    }
};
// @lc code=end

