/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/0H97ZC/)
题目描述
给定 arr1 和 arr2, arr2 中元素各不相同且都出现在 arr1 中。
对 arr1 排序使其相对顺序与 arr2 相同, 未在 arr2 中出现的元素按升序放在末尾。
题目样例
示例1
- 输入: arr1=[2,3,1,3,2,4,6,7,9,2,19], arr2=[2,1,4,3,9,6]
- 输出: [2,2,2,1,4,3,3,9,6,7,19]
题目思考
1. 如何模拟整个过程?
解决方案
思路
- 计数字典统计 arr1 每个元素出现次数
- 先按 arr2 顺序输出所有对应元素
- 再对剩余元素按升序排序后输出
复杂度
- 时间复杂度 O(N1logN1+N2): N1, N2 分别是 arr1, arr2 长度
- 空间复杂度 O(N1): 计数字典
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> cnts;
        for (int x : arr1) cnts[x]++;
        vector<int> res;
        for (int x : arr2)
        {
            int c = cnts[x];
            for (int i = 0; i < c; i++) res.push_back(x);
            cnts.erase(x);
        }
        for (auto &[x, c] : cnts)
            for (int i = 0; i < c; i++) res.push_back(x);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> a1 = {2,3,1,3,2,4,6,7,9,2,19}, a2 = {2,1,4,3,9,6};
    auto r1 = sol.relativeSortArray(a1, a2);
    for (int x : r1) cout << x << " "; cout << endl; // 2 2 2 1 4 3 3 9 6 7 19
    return 0;
}
