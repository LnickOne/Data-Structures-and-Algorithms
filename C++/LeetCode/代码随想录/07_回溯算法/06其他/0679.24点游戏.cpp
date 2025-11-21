/*
给定一个长度为4的整数数组 cards 。你有 4 张卡片，每张卡片上都包含一个范围在 [1,9] 的数字。
您应该使用运算符 ['+', '-', '*', '/'] 和括号 '(' 和 ')'
将这些卡片上的数字排列成数学表达式，以获得值24。

你须遵守以下规则:

除法运算符 '/' 表示实数除法，而不是整数除法。
例如， 4 /(1 - 2 / 3)= 4 /(1 / 3)= 12 。
每个运算都在两个数字之间。特别是，不能使用 “-” 作为一元运算符。
例如，如果 cards =[1,1,1,1] ，则表达式 “-1 -1 -1 -1” 是 不允许 的。
你不能把数字串在一起
例如，如果 cards =[1,2,1,2] ，则表达式 “12 + 12” 无效。
如果可以得到这样的表达式，其计算结果为 24 ，则返回 true ，否则返回 false 。

示例 1:

输入: cards = [4, 1, 8, 7]
输出: true
解释: (8-4) * (7-1) = 24

示例 2:

输入: cards = [1, 2, 1, 2]
输出: false

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool judgePoint24(vector<int> &cards)
    {
        vector<double> nums;
        for (int c : cards)
        {
            nums.push_back((double)c);
        }
        return backtrack(nums);
    }

private:
    bool backtrack(vector<double> nums)
    {
        // 当只剩一个数字时，检查是否接近24（考虑浮点数精度）
        if (nums.size() == 1)
        {
            return abs(nums[0] - 24) < 1e-6;
        }

        int n = nums.size();
        // 尝试所有可能的两个数字组合
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue; // 不能选择同一个数字

                // 创建新的数字列表，包含剩余数字和当前运算结果
                vector<double> nextNums;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                    {
                        nextNums.push_back(nums[k]);
                    }
                }

                double a = nums[i], b = nums[j];

                // 尝试所有四种运算
                // 加法
                nextNums.push_back(a + b);
                if (backtrack(nextNums))
                    return true;
                nextNums.pop_back();

                // 减法
                nextNums.push_back(a - b);
                if (backtrack(nextNums))
                    return true;
                nextNums.pop_back();

                // 乘法
                nextNums.push_back(a * b);
                if (backtrack(nextNums))
                    return true;
                nextNums.pop_back();

                // 除法（注意除数不能为0）
                if (b != 0)
                {
                    nextNums.push_back(a / b);
                    if (backtrack(nextNums))
                        return true;
                    nextNums.pop_back();
                }
            }
        }
        return false;
    }
};
int main()
{
    vector<int> cards = {4, 1, 8, 7};
    Solution s;
    bool result = s.judgePoint24(cards);
    cout << result << endl;
    return 0;
}