/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/7WqeDu/)
题目描述
给定整数数组 nums 和两个整数 k, t。判断是否存在两个不同下标 i, j 使得:
abs(nums[i]-nums[j]) <= t 且 abs(i-j) <= k。
题目样例
示例1
- 输入: nums = [1,2,3,1], k = 3, t = 0
- 输出: true
示例2
- 输入: nums = [1,0,1,1], k = 1, t = 2
- 输出: true
示例3
- 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
- 输出: false
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 桶排序: 桶大小为 t+1, 数字 x 对应桶 id = x/(t+1)
- 负数需特殊处理 (C++ 的除法向零截断): 用 getBucketId 统一处理
- 遍历时只检查当前桶及相邻桶是否有满足条件的数字
- 每个桶只存最新的下标 (同一桶的两个数差值 <= t, 若下标差 <= k 则直接返回 true)
- 遍历结束后移除过期下标 (i-k 对应的桶)
复杂度
- 时间复杂度 O(N): 遍历每个数字一遍
- 空间复杂度 O(k): 滑动窗口内最多 k 个桶
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    long long getBucketId(long long x, long long sz)
    {
        return x >= 0 ? x / sz : (x + 1) / sz - 1;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        if (t < 0) return false;
        long long sz = (long long)t + 1;
        unordered_map<long long, long long> buckets;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            long long x = nums[i];
            long long id = getBucketId(x, sz);
            for (long long nid : {id - 1, id, id + 1})
            {
                if (buckets.count(nid) && abs(x - buckets[nid]) <= t)
                    return true;
            }
            buckets[id] = x;
            if (i >= k) buckets.erase(getBucketId(nums[i - k], sz));
        }
        return false;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    vector<int> n1 = {1, 2, 3, 1};
    cout << sol.containsNearbyAlmostDuplicate(n1, 3, 0) << endl; // true
    vector<int> n2 = {1, 0, 1, 1};
    cout << sol.containsNearbyAlmostDuplicate(n2, 1, 2) << endl; // true
    vector<int> n3 = {1, 5, 9, 1, 5, 9};
    cout << sol.containsNearbyAlmostDuplicate(n3, 2, 3) << endl; // false
    return 0;
}
