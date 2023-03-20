/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // 如果起点有石头，直接返回0
        if(obstacleGrid[0][0]){
            return 0;
        }

        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i = 1 ; i < n; i++){
            if(obstacleGrid[0][i]){
                dp[i]=0;
            }else{
                dp[i]=dp[i-1];
            }
        }

        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0]){
                dp[0] = 0;
            }
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j]){
                    dp[j] = 0;
                }else{
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }

        return dp[n-1];

    }
};
// @lc code=end

