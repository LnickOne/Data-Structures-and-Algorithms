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
        vector<int> result;
        unordered_map<int, int> map;
        vector<int> frequency;
        for (const int &num : nums)
            map[num]++;
        for (const auto &iter : map)
            frequency.push_back(iter.second);
        sort(frequency.begin(), frequency.end(), greater<int>()); // 从大到小排序
        for (int i = 0; i < k; i++)
        {
            for (const auto &iter : map) // 遍历map，将map中value等于frequency的key加入result中
            {
                if (iter.second == frequency[i])
                {
                    result.push_back(iter.first);
                    map.erase(iter.first);
                    break;
                }
            }
        }
        return result;
    }
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[0] > b[0];
    }
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

    return 0;
}
