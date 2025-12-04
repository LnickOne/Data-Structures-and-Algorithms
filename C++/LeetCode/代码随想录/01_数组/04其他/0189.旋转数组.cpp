/*
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释:
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int &k)
    {
        /*
        右旋转，其实就是反转的顺序改动一下，优先反转整个字符串，步骤如下：
        反转整个字符串
        反转区间为前k的子串
        反转区间为k到末尾的子串
        */
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        for (int i = 0; i < nums.size(); ++i)
            cout << nums[i] << " ";
        cout << endl;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(nums, k);
    // for (auto i : nums)
    // {
    //     cout << i << " ";
    // }
    return 0;
}