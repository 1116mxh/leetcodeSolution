/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {

        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));

        pair<int,int> result;

        for(int i=0; i < s.size();i++){
            dp[i][i] = true;
            result.first = i;
            result.second = 1;
        }

        //枚举长度为二的

        for(int L = 2; L <= s.size(); L++ ){

            //枚举起点
            for(int i=0; i < s.size()-1;i++){
                //终点
                int j = i + L -1;
                // 超出范围
                if(j >= s.size()){
                    break;
                }

                if(s[i] == s[j]){
                    if(L==2){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if(dp[i][j]){
                        result.first = i;
                        result.second = L;
                    }
                }

            }

        }

        string temp(s,result.first,result.second);

        return temp;




    }
};
// @lc code=end

