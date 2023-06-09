/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0);
        dp[0] = grid[0][0];
        for(int i = 1; i < n; i++){
            dp[i] = dp[i-1]+grid[0][i];
        }

        for(int i = 1; i < m; i++){
            dp[0] = dp[0] + grid[i][0];
            for(int j = 1; j < n; j++){
                dp[j] = min(dp[j],dp[j-1]) + grid[i][j];
            }
        }

        return dp[n-1];

    }
};
// @lc code=end

