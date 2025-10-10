/*
一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'
然而，在 解码 已编码的消息时，你意识到有许多不同的方式来解码，因为有些编码被包含在其它编码当中（"2" 和 "5" 与 "25"）。
例如，"11106" 可以映射为：
"AAJF" ，将消息分组为 (1, 1, 10, 6)
"KJF" ，将消息分组为 (11, 10, 6)
消息不能分组为  (1, 11, 06) ，因为 "06" 不是一个合法编码（只有 "6" 是合法的）。
注意，可能存在无法解码的字符串。
给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。如果没有合法的方式解码整个字符串，返回 0。
题目数据保证答案肯定是一个 32 位 的整数。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i]：字符串s的前i个字符可以被解码的方案数为dp[i]
    2. 确定递推关系
    dp[i] = dp[i-1] + dp[i-2]
    3. 确定初始值
    dp[0] = 1
    if(s[0]=='0')
    return 0;
    dp[1] = 1
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int first = stoi(s.substr(i - 1, 1));
            int second = stoi(s.substr(i - 2, 2));
            if (first >= 1)
            {
                dp[i] += dp[i - 1];
            }
            if (second >= 10 && second <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
int main()
{
    string s = "226";
    Solution app;

    cout << app.numDecodings(s) << endl;
    return 0;
}