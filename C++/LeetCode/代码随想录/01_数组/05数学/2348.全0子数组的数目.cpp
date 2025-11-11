/*
给你一个整数数组 nums ，返回全部为 0 的 子数组 数目。

子数组 是一个数组中一段连续非空元素组成的序列。

示例 1：
输入：nums = [1,3,0,0,2,0,0,4]
输出：6
解释：
子数组 [0] 出现了 4 次。
子数组 [0,0] 出现了 2 次。
不存在长度大于 2 的全 0 子数组，所以我们返回 6 。

示例 2：
输入：nums = [0,0,0,2,0,0]
输出：9
解释：
子数组 [0] 出现了 5 次。
子数组 [0,0] 出现了 3 次。
子数组 [0,0,0] 出现了 1 次。
不存在长度大于 3 的全 0 子数组，所以我们返回 9 。

示例 3：
输入：nums = [2,10,2019]
输出：0
解释：没有全 0 子数组，所以我们返回 0 。
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long result = 0;
        int current_zero_length = 0;
        for (int num : nums)
        {
            if (num == 0)
            {
                current_zero_length++;
                result += current_zero_length;
            }
            else
            {
                current_zero_length = 0;
            }
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
    Solution solution;
    long long res = solution.zeroFilledSubarray(nums);
    cout << res << endl;
    return 0;
}