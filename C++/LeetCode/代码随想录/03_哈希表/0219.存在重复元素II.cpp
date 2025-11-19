
/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
如果存在，返回 true ；否则，返回 false 。
示例 1：
输入：nums = [1,2,3,1], k = 3
输出：true
示例 2：
输入：nums = [1,0,1,1], k = 1
输出：true
示例 3：
输入：nums = [1,2,3,1,2,3], k = 2
输出：false
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(const vector<int> &nums, int k)
    {
        if (nums.empty())
            return true;
        unordered_map<int, int> map;
        int key;
        int value;
        for (int i = 0; i < nums.size(); i++)
        {
            key = nums[i];
            value = i;
            if (map.find(key) != map.end())
            {
                if (abs(i - map[key] <= k))
                    return true;
            }
            map[key] = value;
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    int k = 2;
    Solution s;
    bool res = s.containsNearbyDuplicate(nums, k);
    cout << res << endl;
    return 0;
}