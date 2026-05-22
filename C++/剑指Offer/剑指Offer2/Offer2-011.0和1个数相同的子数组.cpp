/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/A1NYOS/)
题目描述
给定一个二进制数组 nums, 找到含有相同数量的 0 和 1 的最长连续子数组, 并返回该子数组的长度。
题目样例
示例1
- 输入: nums = [0,1]
- 输出: 2
示例2
- 输入: nums = [0,1,0]
- 输出: 2
题目思考
1. 含有相同数量的 0 和 1 的子数组有什么特点?
解决方案
思路
- 暴力两重循环 O(N^2), 效率较低
- 将 0 视为 -1, 则问题转化为: 找最长子数组使其和为 0, 即前缀和相等
- 维护 0/1 计数差值 diff = zero - one (等价于将 0 视为 -1 的前缀和)
- 用哈希表记录 {差值: 首次出现的下标}, 初始化 first[0] = -1
- 若当前 diff 已在哈希表中, 则 [first[diff]+1, i] 是一个满足条件的子数组, 更新最大长度
- 否则将当前 diff 的首下标加入哈希表
复杂度
- 时间复杂度 O(N): 只需遍历数组一遍
- 空间复杂度 O(N): 哈希表最多包含 N 个元素
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> first;
        first[0] = -1;
        int z = 0, o = 0, res = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (nums[i] == 0) z++;
            else o++;
            int diff = z - o;
            if (first.count(diff)) res = max(res, i - first[diff]);
            else first[diff] = i;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> n1 = {0, 1};
    vector<int> n2 = {0, 1, 0};
    vector<int> n3 = {0, 0, 1, 1, 0, 1};
    cout << s.findMaxLength(n1) << endl; // 2
    cout << s.findMaxLength(n2) << endl; // 2
    cout << s.findMaxLength(n3) << endl; // 4
    return 0;
}
