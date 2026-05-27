/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/qn8gGX/)
题目描述
给定两个升序排列的整数数组 nums1, nums2 和整数 k, 找到和最小的 k 个数对 (u,v)
(u 来自 nums1, v 来自 nums2)。
题目样例
示例1
- 输入: nums1=[1,7,11], nums2=[2,4,6], k=3
- 输出: [[1,2],[1,4],[1,6]]
示例2
- 输入: nums1=[1,1,2], nums2=[1,2,3], k=2
- 输出: [[1,1],[1,1]]
题目思考
1. 如何尽可能优化复杂度?
解决方案
思路
- 最小堆存三元组 (和, i, j), 初始放入 (nums1[0]+nums2[0], 0, 0)
- 每次弹出最小数对, 将紧邻的 (i+1,j) 和 (i,j+1) 加入堆 (用 visited 集合防重)
- 循环 k 次或堆空为止
复杂度
- 时间复杂度 O(KlogK): 只需循环 K 次, 每次堆操作 O(logK)
- 空间复杂度 O(K): 堆和集合各存 K 个元素
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        set<pair<int, int>> visited;
        pq.emplace(nums1[0] + nums2[0], 0, 0);
        visited.emplace(0, 0);
        vector<vector<int>> res;
        while (res.size() < (size_t)k && !pq.empty())
        {
            auto [sm, i, j] = pq.top(); pq.pop();
            res.push_back(vector<int>{nums1[i], nums2[j]});
            for (auto [ni, nj] : vector<pair<int,int>>{make_pair(i+1,j), make_pair(i,j+1)})
            {
                if (ni < (int)nums1.size() && nj < (int)nums2.size() && !visited.count(make_pair(ni, nj)))
                {
                    visited.emplace(ni, nj);
                    pq.emplace(nums1[ni] + nums2[nj], ni, nj);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 7, 11}, n2 = {2, 4, 6};
    auto r1 = sol.kSmallestPairs(n1, n2, 3);
    for (auto &p : r1) cout << "[" << p[0] << "," << p[1] << "] "; cout << endl; // [1,2] [1,4] [1,6]
    vector<int> n3 = {1, 1, 2}, n4 = {1, 2, 3};
    auto r2 = sol.kSmallestPairs(n3, n4, 2);
    for (auto &p : r2) cout << "[" << p[0] << "," << p[1] << "] "; cout << endl; // [1,1] [1,1]
    return 0;
}
