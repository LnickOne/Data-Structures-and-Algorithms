/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。
你可以按 任意顺序 返回答案。
示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:
输入: nums = [1], k = 1
输出: [1]
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int &num : nums)
        {
            map[num]++;
        }
        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> priority_queue;
        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (const auto &iter : map)
        {
            priority_queue.push(iter);
            if (priority_queue.size() > k) // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
            {
                priority_queue.pop();
            }
        }
        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i -= 1)
        {
            result[i] = priority_queue.top().first;
            priority_queue.pop();
        }
        return result;
    }
    // 小顶堆
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };
};

int main()
{
    vector<int> nums_1{1, 1, 1, 2, 2, 3};
    vector<int> nums_2{4, 1, -1, 2, -1, 2, 3};
    int k_1 = 2;
    int k_2 = 2;
    Solution s;
    vector<int> result_1 = s.topKFrequent(nums_1, k_1);
    vector<int> result_2 = s.topKFrequent(nums_2, k_2);
    for (auto i : result_1)
        cout << i << " ";
    cout << endl;
    for (auto i : result_2)
        cout << i << " ";
    cout << endl;
    return 0;
}
