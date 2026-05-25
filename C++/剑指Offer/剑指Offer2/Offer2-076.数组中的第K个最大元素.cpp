/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/xx4gT2/)
题目描述
给定整数数组 nums 和整数 k, 返回数组中第 k 个最大的元素。
题目样例
示例1
- 输入: nums=[3,2,1,5,6,4], k=2
- 输出: 5
示例2
- 输入: nums=[3,2,3,1,2,4,5,5,6], k=4
- 输出: 4
题目思考
1. 可以使用什么数据结构?
解决方案
思路
- 大小为 k 的最小堆: 遍历数组将每个元素加入堆, 超过 k 则弹出堆顶
- 最终堆顶即为第 k 大元素
复杂度
- 时间复杂度 O(NlogK): 遍历 O(N) + 每次堆操作 O(logK)
- 空间复杂度 O(K): 最小堆存储 K 个元素
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums)
        {
            pq.push(x);
            if ((int)pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {3, 2, 1, 5, 6, 4};
    cout << sol.findKthLargest(n1, 2) << endl; // 5
    vector<int> n2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << sol.findKthLargest(n2, 4) << endl; // 4
    return 0;
}
