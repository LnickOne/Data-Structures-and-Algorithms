/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/cyJERH/)
题目描述
由 '0' 和 '1' 组成的字符串, 可将任意字符翻转。返回使 s 单调递增 (所有 '0' 在 '1' 前面) 的最小翻转次数。
题目样例
示例1
- 输入: s="00110"
- 输出: 1
示例2
- 输入: s="010110"
- 输出: 2
示例3
- 输入: s="00011000"
- 输出: 2
题目思考
1. 如何优化时间和空间复杂度?
解决方案
思路
- 双变量滚动 DP: dp0/dp1 分别表示当前字符设为 0/1 的最小翻转次数
- 若 s[i]=='0': dp0 不变, dp1 = min(dp0,dp1)+1
- 若 s[i]=='1': 先暂存旧 dp0, dp1 = min(旧dp0,dp1), dp0 = 旧dp0+1
- 最终结果 min(dp0,dp1)
复杂度
- 时间复杂度 O(N): 遍历一遍
- 空间复杂度 O(1): 常数变量
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int dp0 = 0, dp1 = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                dp1 = min(dp0, dp1) + 1;
            }
            else
            {
                int old0 = dp0;
                dp1 = min(dp0, dp1);
                dp0 = old0 + 1;
            }
        }
        return min(dp0, dp1);
    }
};

int main()
{
    Solution sol;
    cout << sol.minFlipsMonoIncr("00110") << endl;   // 1
    cout << sol.minFlipsMonoIncr("010110") << endl;  // 2
    cout << sol.minFlipsMonoIncr("00011000") << endl; // 2
    return 0;
}
