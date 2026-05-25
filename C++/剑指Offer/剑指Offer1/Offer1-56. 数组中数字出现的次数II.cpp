/* > 题目难度: 中等

> [原题链接](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/)

题目描述

在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

- 1 <= nums.length <= 10000
- 1 <= nums[i] < 2^31

题目样例

示例

- 输入：nums = [3,4,3,3]
- 输出：4

- 输入：nums = [9,1,7,9,7,9,7]
- 输出：1

题目思考

1. 还能使用昨天的异或思路吗?
2. 可以单独统计每一位吗?

解决方案

思路

- 分析题目, 其他数字都出现了三次, 这时候如果还用异或的话, 这些出现 3 次的数字并不能异或为 0, 而是异或成各自自身, 最终异或的结果相当于每个不同的数都异或了一次, 没有任何意义
- 换个角度分析, 如果我们**单独统计每个数字二进制每一位上为 1 的次数并累加**, 那么对于出现 3 次的数而言, 它们的这一位为 1 的次数之和一定是 3 的倍数
- 很显然, 加上了单独出现 1 次的数之后, 这一位上的次数除以 3 的余数要么是 0 (代表这个数字这一位是 0), 要么是 1(代表这个数字这一位是 1), 利用这一点, 我们就能计算出这个数字每一位上到底是 0 还是 1
- 看到这里, 结合上一题 (剑指 Offer 56 - I), 相信聪明的大家都能发现一些规律, 我在这里也总结一下:
  - 其他数字出现**偶数次**, 某个数字出现奇数次: 全部数字异或
  - 其他数字出现**偶数次**, 某两个数字各出现奇数次: 异或后根据异或结果的某个 1 分两类
  - 其他数字出现**奇数次**, 某个数字出现 1 次: 按照二进制每一位统计次数, 然后对这个奇数次取模
- 下面代码对必要的步骤有详细的解释, 方便大家理解

复杂度

- 时间复杂度 O(N): 遍历一遍数组, 然后对于每个数要统计其每一位的次数, 这部分操作是`O(32) == O(1)`, 所以总体复杂度仍为 O(N)
- 空间复杂度 O(1): 只使用了几个变量
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            // 统计所有数字第 i 位上为 1 的次数
            int mask = 1 << i;
            int cnt = 0;
            for (int x : nums)
            {
                if (x & mask)
                    cnt++;
            }
            // 若次数对 3 取余为 1, 则答案在第 i 位上为 1
            if (cnt % 3 == 1)
            {
                res |= mask;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {3, 4, 3, 3};
    cout << sol.singleNumber(nums1) << endl; // 4

    vector<int> nums2 = {9, 1, 7, 9, 7, 9, 7};
    cout << sol.singleNumber(nums2) << endl; // 1

    vector<int> nums3 = {1, 1, 1, 100};
    cout << sol.singleNumber(nums3) << endl; // 100

    return 0;
}
