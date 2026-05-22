/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/kLl5u1/)
题目描述
给定一个已按升序排列的整数数组 numbers, 从数组中找出两个数满足相加之和等于目标数 target。
返回长度为 2 的下标数组 (从 0 开始计数), 且 answer[0] < answer[1]。
题目保证有且只有一对符合条件的数字, 同一个数字不能使用两次。
题目样例
示例1
- 输入: numbers = [1,2,4,6,10], target = 8
- 输出: [1,3]
示例2
- 输入: numbers = [2,3,4], target = 6
- 输出: [0,2]
示例3
- 输入: numbers = [-1,0], target = -1
- 输出: [0,1]
题目思考
1. 如何利用『升序排列』这一条件?
解决方案
思路
- 暴力两重循环 O(N^2) 或哈希集合 O(N) 空间, 都没有利用有序这一条件
- 对有序数组, 使用头尾双指针: 和小于 target 则左指针右移, 和大于 target 则右指针左移, 相等则直接返回
- 由于数组有序且题目保证有唯一答案, 双指针必然找到结果
复杂度
- 时间复杂度 O(N): 只需遍历数组一遍
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        while (i < j)
        {
            int sm = numbers[i] + numbers[j];
            if (sm == target) return {i, j};
            else if (sm < target) i++;
            else j--;
        }
        return {};
    }
};

int main()
{
    Solution s;
    auto print = [](vector<int> v) {
        cout << "[" << v[0] << "," << v[1] << "]" << endl;
    };
    vector<int> n1 = {1, 2, 4, 6, 10};
    vector<int> n2 = {2, 3, 4};
    vector<int> n3 = {-1, 0};
    print(s.twoSum(n1, 8));  // [1,3]
    print(s.twoSum(n2, 6));  // [0,2]
    print(s.twoSum(n3, -1)); // [0,1]
    return 0;
}
