/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集。
输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 方法一
        vector<int> result;
        unordered_map<int, int> map;
        for (int key : nums1)
            map[key]++;
        for (int key : nums2)
            if (map[key] > 0)
            {
                result.push_back(key);
                map[key] = 0;
            }
        return result;
        // 方法二
        // unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        // unordered_set<int> nums_set(nums1.begin(), nums1.end());
        // for (int num : nums2)
        // {
        //     if (nums_set.find(num) != nums_set.end())
        //         result_set.insert(num); // 发现nums2的元素 在nums_set里又出现过
        // }
        // return vector<int>(result_set.begin(), result_set.end());
    }
};

int main()
{
    vector<int> nums1_1 = {1, 2, 2, 1}, nums1_2 = {2, 2};
    vector<int> nums2_1 = {4, 9, 5}, nums2_2 = {9, 4, 9, 8, 4};
    cout << Solution().intersection(nums1_1, nums1_2).size();
    return 0;
}