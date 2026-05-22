/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/WGki4K/)
题目描述
给你一个整数数组 nums, 除某个元素仅出现一次外, 其余每个元素都恰好出现三次。
请你找出并返回那个只出现了一次的元素。
题目样例
示例1
- 输入: nums = [2,2,3,2]
- 输出: 3
示例2
- 输入: nums = [0,1,0,1,0,1,100]
- 输出: 100
题目思考
1. 如何利用恰好出现 3 次这一条件?
2. 如何既做到线性时间复杂度, 又不使用额外空间?
解决方案
思路
- 朴素做法: 用哈希表统计每个数字出现次数, 找到次数为 1 的数字; 线性时间但需要额外空间
- 优化: 换一个角度, 逐位考察二进制每一位上 1 的累计计数
- 其他数字都出现 3 次, 它们在每一位上的贡献是 3 的倍数
- 所以对某一位累加所有数字的该位值, 结果模 3 的余数若为 1, 则目标数字在该位上是 1
- 遍历 32 位, 依次组装出目标数字即可
- C++ 中 int 是 32 位有符号整数, 直接用 unsigned int 处理位组装可避免符号位问题
复杂度
- 时间复杂度 O(N): 外层 32 位循环为常数, 内层遍历每个数字为 O(N), 整体 O(32N) = O(N)
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unsigned int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            unsigned int cnt = 0;
            for (int x : nums)
                cnt += ((unsigned int)x >> i) & 1;
            if (cnt % 3 == 1)
                res |= (1u << i);
        }
        return (int)res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 2, 3, 2};
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 100};
    vector<int> nums3 = {-2, -2, -2, 5};
    cout << s.singleNumber(nums1) << endl; // 3
    cout << s.singleNumber(nums2) << endl; // 100
    cout << s.singleNumber(nums3) << endl; // 5
    return 0;
}
