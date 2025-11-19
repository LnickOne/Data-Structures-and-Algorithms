/*
给你一个按 非递减顺序 排序的整数数组 nums，
返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
    vector<int> sortedSquares_1(vector<int> &nums)
    {
        vector<int> result(nums.size());
        int index = nums.size() - 1;
        int right = nums.size() - 1;
        for (int left = 0; left <= right;)
        { // 注意这里要i <= j，因为最后要处理两个元素
            if (nums[left] * nums[left] < nums[right] * nums[right])
            {
                result[index] = nums[right] * nums[right];
                right--;
                index--;
            }
            else
            {
                result[index] = nums[left] * nums[left];
                left++;
                index--;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = s.sortedSquares(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}