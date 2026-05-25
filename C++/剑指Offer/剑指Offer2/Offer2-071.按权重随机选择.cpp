/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/cuyjEf/)
题目描述
给定正整数数组 w, w[i] 代表下标 i 的权重, 实现 pickIndex 函数:
以 w[i]/sum(w) 的概率随机选择下标 i 并返回。
题目样例
示例1
- 输入: ["Solution","pickIndex"] [[[1]],[]]
- 输出: [null,0]
示例2
- 输入: ["Solution","pickIndex","pickIndex"] [[[1,3]],[],[]]
- 输出: [null,1,1] (或其他符合概率的输出)
题目思考
1. 如何设计随机算法?
2. 如何优化时间复杂度?
解决方案
思路
- 构建前缀和数组 sms (sms[i] = w[0]+...+w[i-1])
- pickIndex 时随机生成 [0, total) 的数 x, 二分查找第一个 sms[i] > x 的 i-1 即为结果
- 使用 upper_bound 找到第一个严格大于 x 的位置, 减 1 即下标
复杂度
- 时间复杂度 O(logN): 每次 pickIndex 使用二分查找
- 空间复杂度 O(N): 前缀和数组
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution
{
    vector<int> sms;

public:
    Solution(vector<int> &w)
    {
        sms.push_back(0);
        for (int x : w)
            sms.push_back(sms.back() + x);
    }
    int pickIndex()
    {
        int x = rand() % sms.back();
        auto it = upper_bound(sms.begin(), sms.end(), x);
        return (int)(it - sms.begin()) - 1;
    }
};

int main()
{
    vector<int> w1 = {1};
    Solution s1(w1);
    cout << s1.pickIndex() << endl; // 0
    vector<int> w2 = {1, 3};
    Solution s2(w2);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 1000; i++)
    {
        int idx = s2.pickIndex();
        if (idx == 0)
            cnt0++;
        else
            cnt1++;
    }
    cout << "idx0: " << cnt0 << " idx1: " << cnt1 << endl; // ~250:750
    return 0;
}
