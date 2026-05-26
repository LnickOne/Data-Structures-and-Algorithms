/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/1fGaJU/)
题目描述
给你一个整数数组 nums, 判断是否存在三元组 [nums[i],nums[j],nums[k]] 满足 i!=j、i!=k 且 j!=k,
同时 nums[i]+nums[j]+nums[k]==0。返回所有和为 0 且不重复的三元组。
题目样例
示例1
- 输入: nums = [-1,0,1,2,-1,-4]
- 输出: [[-1,-1,2],[-1,0,1]]
示例2
- 输入: nums = [0,1,1]
- 输出: []
示例3
- 输入: nums = [0,0,0]
- 输出: [[0,0,0]]
题目思考
1. 如何尽可能优化时间复杂度?
解决方案
思路
- 暴力三重循环 O(N^3), 效率太低
- 先排序, 固定第一个数 a, 对剩余子数组用双指针求两数之和为 -a, 转化为上一题
- 排序后相邻重复值只处理一次 (去重1): 若 nums[i]==nums[i-1] 则跳过
- 找到有效三元组后与结果末尾比较去重 (去重2)
- 两处剪枝: a+相邻两数>0 则 break; a+末尾两数<0 则 continue
复杂度
- 时间复杂度 O(N^2): 排序 O(NlogN), 外层 O(N) * 内层双指针 O(N)
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++)
        {
            int a = nums[i];
            if (i > 0 && a == nums[i - 1])
                continue;
            if (a + nums[i + 1] + nums[i + 2] > 0)
                break;
            if (a + nums[n - 1] + nums[n - 2] < 0)
                continue;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sm = a + nums[j] + nums[k];
                if (sm == 0)
                {
                    if (res.empty() || res.back() != vector<int>{a, nums[j], nums[k]})
                        res.push_back({a, nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sm < 0)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    auto print = [](vector<vector<int>> &v)
    {
        cout << "[";
        for (int i = 0; i < (int)v.size(); i++)
        {
            if (i)
                cout << ",";
            cout << "[" << v[i][0] << "," << v[i][1] << "," << v[i][2] << "]";
        }
        cout << "]" << endl;
    };
    vector<int> n1 = {-1, 0, 1, 2, -1, -4};
    vector<int> n2 = {0, 1, 1};
    vector<int> n3 = {0, 0, 0};
    auto r1 = s.threeSum(n1);
    auto r2 = s.threeSum(n2);
    auto r3 = s.threeSum(n3);
    print(r1); // [[-1,-1,2],[-1,0,1]]
    print(r2); // []
    print(r3); // [[0,0,0]]
    return 0;
}
