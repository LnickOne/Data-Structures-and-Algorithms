/*
给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），
返回 nums 中每个元素的 下一个更大元素 。
数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，
这意味着你应该循环地搜索它的下一个更大的数。
如果不存在，则输出 -1 。

示例 1:
输入: nums = [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。

示例 2:
输入: nums = [1,2,3,4,3]
输出: [2,3,4,-1,4]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> result;
        stack<int> s;
        int n = nums.size();
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i % n])
            {
                s.pop();
            }
            result.push_back(s.empty() ? -1 : s.top());
            s.push(nums[i % n]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1};
    Solution s;
    vector<int> result = s.nextGreaterElements(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}