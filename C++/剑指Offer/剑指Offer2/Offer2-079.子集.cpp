/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/TVdhkn/)
题目描述
给定元素互不相同的整数数组 nums, 返回该数组所有可能的子集 (幂集)。
题目样例
示例1
- 输入: nums = [1,2,3]
- 输出: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例2
- 输入: nums = [0]
- 输出: [[],[0]]
题目思考
1. 如果限制只能用递归或者迭代, 如何解决?
解决方案
思路
- 回溯 DFS: 从下标 i 开始, 两种选择: 选取或不选取 nums[i], 递归到末尾时记录子集
- 也可用位运算迭代: 遍历 0~2^n-1 所有 mask, 第 i 位为 1 则选取 nums[i]
复杂度
- 时间复杂度 O(N*2^N): 共 2^N 个子集, 每个构建需要 O(N)
- 空间复杂度 O(N): 递归栈深度
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(vector<int> &nums, int i)
    {
        if (i == (int)nums.size())
        {
            res.push_back(cur);
            return;
        }
        dfs(nums, i + 1);
        cur.push_back(nums[i]);
        dfs(nums, i + 1);
        cur.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        res.clear();
        cur.clear();
        dfs(nums, 0);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 2, 3};
    auto r1 = sol.subsets(n1);
    for (auto &s : r1)
    {
        cout << "[";
        for (int i = 0; i < (int)s.size(); i++) { if (i) cout << ","; cout << s[i]; }
        cout << "] ";
    }
    cout << endl; // 所有子集
    return 0;
}
