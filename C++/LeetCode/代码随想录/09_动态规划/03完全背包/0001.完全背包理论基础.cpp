/*
完全背包的核心思想:遍历背包容量的顺序使用正序遍历,不使用倒序,从而可以让物品使用多次。
并且完全背包一维dp数组的两个for遍历的先后循序是可以颠倒。
1. 最优化问题（求最大/最小值）
// 状态转移方程
dp[j] = max(dp[j], dp[j - weight[i]] + value[i])  // 求最大值
dp[j] = min(dp[j], dp[j - weight[i]] + value[i])  // 求最小值

// 遍历顺序：可以颠倒
// 先遍历物品再遍历背包 或 先遍历背包再遍历物品 都可以
for (int i = 0; i < weight.size(); i+=1)                  // 遍历物品
    for (int j = weight[i]; j <= backpack_capacity; j+=1) // 遍历背包容量,后遍历背包从物品的重量开始,求组合数
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i])  // 求最大值
        dp[j] = min(dp[j], dp[j - weight[i]] + value[i])  // 求最小值

for (int j = 0; j <= backpack_capacity; j+=1) // 遍历背包容量,先遍历背包从0开始，求排列数
    for (int i = 0; i < weight.size(); i+=1) // 遍历物品,因为背包容量是0了,所以物品也可以从0开始,但其实指的是第一个物品的重量
        if (j - weight[i] >= 0) // 并且要加上判断语句是否能装上物品
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
2. 计数问题（求方案数）
// 状态转移方程
dp[j] += dp[j - nums[i]]  // 累加方案数
// 遍历顺序：不能颠倒，有严格要求
// 求组合数：先遍历物品再遍历背包
// 求排列数：先遍历背包再遍历物品

### 为什么先遍历背包容量再遍历物品能得到排列？
关键在于 遍历顺序 ：
- 先遍历背包容量 j （从0到target）
- 再遍历物品 nums[i]
这样做的好处是：对于同一个容量 j ，我们会考虑所有可能的物品 nums[i] 作为 最后一个元素 。
*/
