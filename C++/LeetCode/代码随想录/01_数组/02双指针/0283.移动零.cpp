/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意，必须在不复制数组的情况下原地对数组进行操作。
示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:
输入: nums = [0]
输出: [0]
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // // 方法一
        // int slow = 0;
        // for (int fast = 0; fast < nums.size(); ++fast)
        // {
        //     if (nums[fast] != 0)
        //     {
        //         nums[slow] = nums[fast];
        //         ++slow;
        //     }
        // }
        // for (int i = slow; i < nums.size(); ++i)
        // {
        //     nums[i] = 0;
        // }
        // 方法二
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
            if(nums[right]== 0)
                right++;
        }
    }
};
int main()
{
    vector<int> nums_1 = {0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(nums_1);
    for (int i = 0; i < nums_1.size(); i++)
    {
        cout << nums_1[i] << " ";
    }
    cout << endl;
    return 0;
}