/*
给你一个 只包含正整数 的 非空 数组 nums 。
请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
提示：
1 <= nums.length <= 200
1 <= nums[i] <= 100
 */
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[j]表示容量为j的背包，所背物品的最大价值为dp[j]。
    背包的容量为sum / 2
    背包要放入的商品重量为元素的数值，价值也为元素的数值,背包中每一个元素是不可重复放入。
    背包如果正好装满，说明找到了总和为 sum / 2 的子集。
    因此dp[j] 表示容量为 j 的背包，所背的物品价值最大为 dp[j]。
    2. 确定递推关系
    dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    3. 确定初始值
    dp[0]=0;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) // 奇数不能平分
            return false;
        int backpack_capacity = sum / 2;          // 背包容量为总和的一半
        vector<int> dp(backpack_capacity + 1, 0); // 背包
        for (int i = 0; i < nums.size(); i++)     // 遍历物品
        {
            for (int j = backpack_capacity; j >= nums[i]; j--) // 遍历背包
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
        cout << dp[backpack_capacity] << endl;
        return dp[backpack_capacity] == sum / 2;
    }
};
int main()
{
    vector<int> nums_1 = {1, 5, 11, 5};
    vector<int> nums_2 = {1, 2, 3, 5};
    Solution().canPartition(nums_1);
    Solution().canPartition(nums_2);
    return 0;
}