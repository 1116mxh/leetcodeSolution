/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:

    vector<string> result;
    string temp;
    vector<string> generateParenthesis(int n) {

        help(n,0);

        return result;

    }
    // n代表总共能放入几个“（”,num代表已经放入几个“(”
    void help(int n,int num){
        if(n == 0 && num == 0){
            result.push_back(temp);
        }
        if(num > 0){
            // 可以放入")"
            temp.push_back(')');
            help(n,num-1);
            temp.pop_back();
        }
        if(n > 0){
            // 可以放入"("
            temp.push_back('(');
            help(n-1,num+1);
            temp.pop_back();
        }
    }

};
// @lc code=end

