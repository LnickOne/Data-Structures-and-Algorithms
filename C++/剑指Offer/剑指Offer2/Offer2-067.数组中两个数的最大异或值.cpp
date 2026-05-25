/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/ms70jA/)
题目描述
给定整数数组 nums, 返回 nums[i] XOR nums[j] 的最大运算结果 (0<=i<=j<n)。
题目样例
示例1
- 输入: nums = [3,10,5,25,2,8]
- 输出: 28 (5^25=28)
示例2
- 输入: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
- 输出: 127
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 贪心前缀匹配: 从最高位到最低位, 每次尽量让当前位的异或为 1
- 将所有数字的当前前缀放入 unordered_set, 假设当前最大前缀 res 此位为 1
- 检查是否存在 x >> k 使得 (res ^ (x >> k)) 也在集合中, 若存在则该位确实为 1, 否则置 0
复杂度
- 时间复杂度 O(N): 外层 32 次循环为常数, 内层遍历数组一遍
- 空间复杂度 O(N): 集合存储所有前缀
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int res = 0;
        for (int k = 31; k >= 0; k--)
        {
            unordered_set<int> v;
            for (int x : nums) v.insert(x >> k);
            int candidate = (res << 1) | 1;
            bool found = false;
            for (int x : nums)
            {
                if (v.count(candidate ^ (x >> k))) { found = true; break; }
            }
            res = found ? candidate : (res << 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {3, 10, 5, 25, 2, 8};
    cout << sol.findMaximumXOR(n1) << endl; // 28
    vector<int> n2 = {0};
    cout << sol.findMaximumXOR(n2) << endl; // 0
    vector<int> n3 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << sol.findMaximumXOR(n3) << endl; // 127
    return 0;
}
