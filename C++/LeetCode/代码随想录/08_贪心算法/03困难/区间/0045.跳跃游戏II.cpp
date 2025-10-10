#include <iostream>
#include <vector>
using namespace std;
/*
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
0 <= j <= nums[i]
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
示例 1:
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
示例 2:
输入: nums = [2,3,0,1,4]
输出: 2
*/
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return 0;
        int result = 0;
        int cur_cover = 0;  // 当前覆盖的最远距离下标
        int next_cover = 0; // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size(); ++i)
        {
            next_cover = max(nums[i] + i, next_cover); // 收集下一步覆盖最远距离
            if (i == cur_cover)
            {                                     // 遇到当前覆盖最远距离下标
                result++;                         // 需要走下一步
                cur_cover = next_cover;           // 更新当前覆盖最远距离下标（相当于加油了）
                if (cur_cover >= nums.size() - 1) // 当前覆盖最远距到达集合终点，不用做++操作了，直接结束
                    break;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}