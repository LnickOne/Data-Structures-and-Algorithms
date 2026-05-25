/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/g5c51o/)
题目描述
给定整数数组 nums 和整数 k, 返回出现频率前 k 高的元素 (可按任意顺序返回)。
题目样例
示例1
- 输入: nums = [1,1,1,2,2,3], k = 2
- 输出: [1,2]
示例2
- 输入: nums = [1], k = 1
- 输出: [1]
题目思考
1. 可以使用什么数据结构?
解决方案
思路
- 先用 unordered_map<int,int> 统计每个元素的出现频率
- 用大小为 k 的最小堆 (按频率排序), 维护出现频率最高的 k 个元素
- 遍历频率 map, 将 (频率, 元素) 加入堆, 超过 k 则弹出堆顶
复杂度
- 时间复杂度 O(NlogK): 统计频率 O(N) + 堆操作 O(NlogK)
- 空间复杂度 O(N): 频率字典 O(N) + 堆 O(K)
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnts;
        for (int x : nums) cnts[x]++;
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        for (auto &[num, cnt] : cnts)
        {
            pq.push({cnt, num});
            if ((int)pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) { res.push_back(pq.top().second); pq.pop(); }
        return res;
    }
};

int main()
{
    Solution sol;
    auto print = [](vector<int> &v) { for (int x : v) cout << x << " "; cout << endl; };
    vector<int> n1 = {1, 1, 1, 2, 2, 3};
    auto r1 = sol.topKFrequent(n1, 2);
    print(r1); // 1 2 (顺序不定)
    vector<int> n2 = {1};
    auto r2 = sol.topKFrequent(n2, 1);
    print(r2); // 1
    return 0;
}
