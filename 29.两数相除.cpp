/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {

        //注意：有符号整形，负的范围要比整的范围多一个，所以负的取负号会导致正的溢出，但是正的取负号没有问题

        if(dividend == INT_MIN){
            if(divisor == 1){
                return INT_MIN;
            }
            if(divisor == -1){
                return INT_MAX;
            }
        }

        if(dividend == 0){
            return 0;
        }
        if(divisor == INT_MIN){
            return dividend == divisor ? 1 : 0;
        }

        int result = 0;

        if(dividend == INT_MIN){
            dividend -= -abs(divisor);
            result++;
        }

        // false为正数，true为负数 上面的操作主要是避免出现最小值
        bool sign = false;
        if(dividend < 0){
            sign = !sign;
            dividend = -dividend;
        }
        if(divisor < 0){
            sign = !sign;
            divisor = -divisor;
        }

        // vector<int> tempNum{divisor};

        // // 二分法计算最接近dividend的值，第n次代表2的n-1次方个dividsor相加，此时全部累加和是2的n次方-1个dividsor，且刚好2的n次方个dividsor相加大于dividend
        // while(tempNum.back() >= dividend - tempNum.back()){
        //     tempNum.push_back(tempNum.back()+tempNum.back());
        // }
        // for(int i = tempNum.size()-1; i >=0; i--){

        //     if(dividend <= tempNum[i]){
        //         // 计算 2的i次方
        //         result += (1 << i);
        //         dividend -= tempNum[i];
        //     }

        // }

        // 必须倒着试，寻找divisor向左移多少位是小于dividend的最大值，即在向左移动一位就会大于dividend
        for(int i = 31; i >= 0; i--){
            if((dividend >> i) >= divisor){
                result += (1<<i);
                dividend -= (divisor<<i);
            }
        }


        return sign ? -result : result;


    }

    
};
// @lc code=end

