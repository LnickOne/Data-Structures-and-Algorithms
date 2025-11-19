#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
/*
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。
那么粉碎的可能结果如下：
如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
示例 1：
输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
示例 2：
输入：stones = [31,26,33,21,40]
输出：5
 */
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    只需要将这些石头尽可能地分成两堆，如果两堆重量相似的话相撞之后所剩的值就是最小值。
    dp[j]表示容量（这里说容量更形象，其实就是重量）为j的背包，最多可以背最大重量为dp[j]。
    可以回忆一下01背包中，dp[j]的含义，容量为j的背包，最多可以装的价值为 dp[j]。
    相对于 01背包，本题中，石头的重量是 stones[i]，石头的价值也是 stones[i]
    可以 “最多可以装的价值为 dp[j]” == “最多可以背的重量为dp[j]”
    2. 确定递推关系
    01背包的递推公式为：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    本题则是：dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
    一些同学可能看到这dp[j - stones[i]] + stones[i]中 又有- stones[i] 又有+stones[i]，看着有点晕乎。
    3. 确定初始值
    既然 dp[j]中的j表示容量，那么最大容量（重量）是多少呢，就是所有石头的重量和。
    因为提示中给出1 <= stones.length <= 30，1 <= stones[i] <= 1000，所以最大重量就是30 * 1000 。
    而我们要求的target其实只是最大重量的一半，所以dp数组开到15000大小就可以了。
    当然也可以把石头遍历一遍，计算出石头总重量 然后除2，得到dp数组的大小。
    我这里就直接用15000了。
    接下来就是如何初始化dp[j]呢，因为重量都不会是负数，
    所以dp[j]都初始化为0就可以了，
    这样在递归公式dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);中dp[j]才不会初始值所覆盖。
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int backpack_capacity = sum / 2;
        vector<int> dp(backpack_capacity + 1, 0);
        for (int i = 0; i < stones.size(); i++) // 遍历物品
        {
            for (int j = backpack_capacity; j >= stones[i]; j--) // 遍历背包
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
        return sum - dp[backpack_capacity] - dp[backpack_capacity]; // 分成两堆石头，大的一堆去撞小的一堆
    }
};

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution solve;
    cout << solve.lastStoneWeightII(stones) << endl;
    return 0;
}