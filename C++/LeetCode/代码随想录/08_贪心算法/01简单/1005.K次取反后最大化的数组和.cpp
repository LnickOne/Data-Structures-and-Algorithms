#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
以这种方式修改数组后，返回数组 可能的最大和 。
示例 1：
输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。
示例 2：
输入：nums = [3,-1,0,2], k = 3
输出：6
解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
示例 3：
输入：nums = [2,-3,-1,5,-4], k = 2
输出：13
解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4]
*/
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), compare);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }
        if (k % 2 == 1) // 如果剩下的k为奇数则将最后一个数变为相反数
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        int result = accumulate(nums.begin(), nums.end(), 0);
        return result;
    }
    static bool compare(int a, int b)
    {
        return abs(a) > abs(b);
    }
};

int main()
{
    vector<int> nums = {2, -3, -1, 5, -4};
    int k = 2;
    Solution s;
    cout << s.largestSumAfterKNegations(nums, k);
}