/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
    int slen = s.size();
    int plen = p.size();
    vector<vector<bool>> dp(plen+1,vector<bool>(slen+1,false));
    dp[0][0] = true;
    //初始化第一列，（s为空字符串时，p是否能匹配，p只要不是‘*’就可定不能匹配，如果是，可以认为字符+*为空不占用字符串，则有可能匹配）
    for(int i = 1; i < plen+1;i++){
        if(p[i-1] == '*'){
            dp[i][0] = dp[i-2][0];
        }
    }

    for(int i = 1; i < plen+1; i++){
        for(int j = 1; j < slen+1; j++){
            if(p[i-1] == '*'){
                // 先获得不要符号+*号的结果
                dp[i][j] = dp[i-2][j];
                // 如果上一个符号和s当前的符号相等，则可以考虑用来消去s当前的符号，这时不计算s当前符号是否能匹配即可
                if(p[i-2] == s[j-1] || p[i-2] == '.'){
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }else{
                // 如果不是‘*’且相等，就看斜上角是否匹配
                if(p[i-1] == s[j-1] || p[i-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
    }

    return dp[plen][slen];

    }
};


// @lc code=end

