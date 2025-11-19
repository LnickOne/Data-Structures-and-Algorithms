/*
给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target 的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]
*/
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        int key, value;
        for (int i = 0; i < nums.size(); i += 1)
        {
            key = nums[i];
            value = i;
            // unordered_map<int, int>::iterator iterator = map.find(target - key);
            const auto &iterator = map.find(target - key);
            if (iterator != map.end())
                return {iterator->second, i};
            map[key] = value;
        }
        return {};
    }
};

int main()
{
    vector<int> nums_1 = {1, 2, 3, 4, 5};
    int nums_2[] = {1, 2, 3, 4, 5};
    int target = 5;
    Solution s;
    vector<int> result = s.twoSum(nums_1, target);
    for (int &i : result)
        cout << i << endl;
    return 0;
}