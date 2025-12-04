/*
给你一个仅由数字 6 和 9 组成的正整数 num。
你最多只能翻转一位数字，将 6 变成 9，或者把 9 变成 6 。
请返回你可以得到的最大数字。
示例 1：
输入：num = 9669
输出：9969
解释：
改变第一位数字可以得到 6669 。
改变第二位数字可以得到 9969 。
改变第三位数字可以得到 9699 。
改变第四位数字可以得到 9666 。
其中最大的数字是 9969 。
示例 2：
输入：num = 9996
输出：9999
解释：将最后一位从 6 变到 9，其结果 9999 是最大的数。
示例 3：
输入：num = 9999
输出：9999
解释：无需改变就已经是最大的数字了。
提示：
1 <= num <= 10^4
num 每一位上的数字都是 6 或者 9 。
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maximum69Number(int num)
    {
        string numStr = to_string(num);
        for (char &num : numStr)
        {
            if (num == '6')
            {
                num = '9';
                break;
            }
        }
        return stoi(numStr);
    }
};

int main()
{
    Solution s;
    int num = 9669;
    int num1 = 9996;
    int num2 = 9999;
    int res = s.maximum69Number(num);
    int res1 = s.maximum69Number(num1);
    int res2 = s.maximum69Number(num2);
    cout << res << endl;
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}