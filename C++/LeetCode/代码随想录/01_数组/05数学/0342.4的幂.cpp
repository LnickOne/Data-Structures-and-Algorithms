/*
给定一个整数，写一个函数来判断它是否是 3 的幂次方。
如果是，返回 true ；否则，返回 false 。
整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x
示例 1：
输入：n = 27
输出：true
示例 2：
输入：n = 0
输出：false
示例 3：
输入：n = 9
输出：true
示例 4：
输入：n = 45
输出：false
提示：
-231 <= n <= 231 - 1
进阶：你能不使用循环或者递归来完成本题吗？
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;

        while (n % 4 == 0) // 循环除以4，直到n不再能被4整除
        {
            n /= 4;
        }

        return n == 1; // 如果最终结果是1，则是4的幂次方
    }
};

// 测试用例
int main()
{
    Solution s;
    cout << s.isPowerOfFour(16) << endl; // true
    cout << s.isPowerOfFour(15) << endl; // false
    cout << s.isPowerOfFour(1) << endl;  // true
    cout << s.isPowerOfFour(0) << endl;  // false
    cout << s.isPowerOfFour(-4) << endl; // false
    return 0;
}