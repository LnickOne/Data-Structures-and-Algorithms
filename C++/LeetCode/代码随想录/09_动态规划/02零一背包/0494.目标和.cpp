#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
/*
给你一个非负整数数组 nums 和一个整数 target 。
向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
示例 1：
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
示例 2：
输入：nums = [1], target = 1
输出：1
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    本题分出加法left一个集合(给元素"+"号)，减法right一个集合(给元素"-"号),
    因此left+right=sum所有集合sum也为nums所有元素的和,因此可以得到
    left+right=sum
    left-right=target
    right=sum-left
    结合后得到left,left又是正数加法集合，比如本题target=3 sum=5 则left=4,集合里能挑出哪些元素凑出和等于4，找出正数的集合，剩下就是负数的集合了
    left-(sum-left)=target
    left=(target+sum)/2,left即为背包的容量
    dp[j]：表示容量为j的背包里有多少种方案
    2. 确定递推关系
    放每一个物品的状态可以推出dp[j],即dp[j]=dp[j-nums[i]]
    比如 有一个物品1 则有dp[4]种方法凑出dp[5],有一个物品2，则有dp[3]种方法凑出dp[5]
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int findTargetSumWays(const vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) // 此时没有方案
            return 0;
        if ((target + sum) % 2 != 0) // 若是为奇数没有方案
            return 0;
        int backpack_capacity = (target + sum) / 2; // 背包容量
        vector<int> dp(backpack_capacity + 1, 0);
        dp[0] = 1;                            // 不同于求最大价值初始化为0。其他下标可以初始化为0,因为是求有多少种装法，多少种方式或者方法。什么都不装也是一种装法，所以初始化为1。
        for (int i = 0; i < nums.size(); i++) // 遍历物品
        {
            for (int j = backpack_capacity; j >= nums[i]; j--) // 遍历背包
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[backpack_capacity];
    }
};
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    Solution sol;
    cout << sol.findTargetSumWays(nums, target);
    return 0;
}