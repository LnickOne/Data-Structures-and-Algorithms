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
    /*
    递归实现思路
    终止条件：
    当 n == 1 时返回 true（3⁰ = 1） 当 n < 1 或 n % 3 != 0 时返回 false（非正数或不能被3整除）
    递归逻辑：将原问题拆解为 n /3 的子问题，持续缩小规模直至触发终止条件
    注意事项
    递归深度：对于int范围内最大的3的幂次方（3¹⁹ = 1162261467），
    递归深度仅为19层，不会导致栈溢出
    负数处理：由于3的任何次幂都是正数，直接通过 n < 1 排除所有负数和0                                                                                                                                                                                         时间复杂度：O(log₃n)，空间复杂度：O(log₃n)（递归调用栈开销） */

    bool isPowerOfThree(int n)
    {
        if (n == 1) // 递归终止条件
            return true;
        if (n < 1 || n % 3 != 0)
            return false;
        // 递归调用：将问题规模缩小为n/3
        return isPowerOfThree(n / 3);
    }

    // bool isPowerOfThree(int n)
    // {
    //     /*
    //     循环实现思路
    //     边界处理：首先排除所有非正数（3的任何次幂都是正数）
    //     循环逻辑：持续将n除以3，直到n不能被3整除
    //     结果判断：若最终n等于1，则原数是3的幂次方（3⁰ = 1）
    //     复杂度分析
    //     时间复杂度：O(log₃n)，循环次数等于n中包含的3的幂次
    //     空间复杂度：O(1)，仅使用常数额外空间
    //     */
    //     // 处理边界情况：非正数直接返回false
    //     if (n <= 0)
    //         return false;
    //     // 循环除以3，直到n不再能被3整除
    //     while (n % 3 == 0)
    //     {
    //         n /= 3;
    //     }
    //     // 如果最终结果是1，则是3的幂次方
    //     return n == 1;
    // }
    // bool isPowerOfThree(int n)
    // {
    //     /*
    //     数学特性：3的幂次方在int范围内的最大值是3^19 = 1162261467
    //     整除特性：若n是3的幂次方，则1162261467必然能被n整除
    //     边界处理：排除n ≤ 0的情况（3的任何次幂都是正数）
    //     该方法时间复杂度O(1)，空间复杂度O(1)，满足进阶要求（不使用循环/递归）
    //     */
    //     if (n <= 0)
    //         return false;
    //     const int maxPower = 1162261467; // 3^19是int范围内最大的3的幂次方
    //     return maxPower % n == 0;
    // }
};

// 测试用例
int main()
{
    Solution s;
    cout << boolalpha;
    cout << s.isPowerOfThree(27) << endl; // true
    cout << s.isPowerOfThree(0) << endl;  // false
    cout << s.isPowerOfThree(9) << endl;  // true
    cout << s.isPowerOfThree(45) << endl; // false
    return 0;
}