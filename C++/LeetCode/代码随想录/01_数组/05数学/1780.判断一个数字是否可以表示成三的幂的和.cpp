/*
给你一个整数 n ，如果你可以将 n 表示成若干个不同的三的幂之和，请你返回 true ，否则请返回 false 。
对于一个整数 y ，如果存在整数 x 满足 y == 3x ，我们称这个整数 y 是三的幂。
示例 1：
输入：n = 12
输出：true
解释：12 = 31 + 32
示例 2：
输入：n = 91
输出：true
解释：91 = 30 + 32 + 34
示例 3：
输入：n = 21
输出：false
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        bool result = false;
        while (n > 0)
        {
            if (n % 3 == 0) // 当前位是0，直接整除3继续判断更高位
            {
                n /= 3;
            }
            else if (n % 3 == 1) // 当前位是1，减去1后整除3，标记result为true
            {
                n = (n - 1) / 3;
                result = true; // 至少有一个1，可能是有效解
            }
            else if (n % 3 == 2) // 当前位是2，直接返回false（三进制中不允许出现2）
            {
                return false;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    bool result1 = s.checkPowersOfThree(12);
    bool result2 = s.checkPowersOfThree(91);
    bool result3 = s.checkPowersOfThree(21);
    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;
    return 0;
}