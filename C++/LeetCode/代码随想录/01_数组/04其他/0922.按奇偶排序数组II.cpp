/*
给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。
对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。
你可以返回 任何满足上述条件的数组作为答案 。
示例 1：
输入：nums = [4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
示例 2：
输入：nums = [2,3]
输出：[2,3]
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i += 2)
        {
            for (int j = 1; j < nums.size(); j += 2)
            {
                if (nums[i] % 2 == 0)
                    continue;
                if (nums[j] % 2 == 1)
                    continue;
                if (nums[i] % 2 == 1 && nums[j] % 2 == 0)
                    swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};

int main()
{
    return 0;
}