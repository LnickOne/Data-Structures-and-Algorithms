/*
给你一个有序数组 nums，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，
返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
示例 1：
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。
不需要考虑数组中超出新长度后面的元素。
示例 2：
输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。
不需要考虑数组中超出新长度后面的元素。
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
    int removeDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int key;
        for (int i = 0; i < nums.size(); i += 1)
        {
            key = nums[i];
            map[key]++;
            if (map[key] > 2)
            {
                nums.erase(nums.begin() + i);
                i -= 1;
            }
        }
        return nums.size();
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> nums1 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution s;
    s.removeDuplicates(nums1);
    for (int i = 0; i < nums1.size(); i += 1)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}