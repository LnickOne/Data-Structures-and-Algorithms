#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬至多m (1 <= m < n)个台阶。
你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
输入描述：输入共一行，包含两个正整数，分别表示n, m
输出描述：输出一个整数，表示爬到楼顶的方法数。
输入示例：3 2
输出示例：3
提示：
当 m = 2，n = 3 时，
n = 3 这表示一共有三个台阶，m = 2 代表你每次可以爬一个台阶或者两个台阶。
此时你有三种方法可以爬到楼顶。
1 阶 + 1 阶 + 1 阶段
1 阶 + 2 阶
2 阶 + 1 阶
爬楼梯(完全背包)是求排列，因此先遍历背包的容量，再遍历物品。
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[j]：爬到第n阶的楼顶，每次可以爬至多m个台阶,有dp[j]种方法。
    2. 确定递推关系
    完全背包下求装满背包有几种方法，递推公式是dp[j] =dp[j]+dp[j - i];
    本题求dp[j]有多种来源，dp[j - 1]，dp[j - 2]，dp[j - 3] 等等，即：dp[j - i]
    因此递推公式为：
    if(j>=i)
        dp[j] =dp[j]+dp[j - i];
    3. 确定初始值
    既然递归公式是：dp[j] =dp[j]+dp[j - i]，那么dp[0] 一定为1
    4. 确定遍历顺序
    这是背包里求排列问题，即：1、2 步 和 2、1 步都是上三个台阶，但是这两种方法不一样.
    所以需将背包放在外循环，将物品放在内循环。
    5. 举例推导dp数组
    */
    int climbStairs(int n, int m)
    {
        int backpack_capacity = n;
        vector<int> dp(backpack_capacity + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= backpack_capacity; j++) // 求排列数，遍历背包
        {
            for (int i = 1; i <= m; i++) // 遍历物品
            {
                if (j >= i)
                {
                    dp[j] = dp[j] + dp[j - i];
                }
            }
        }
        return dp[backpack_capacity];
    }
};
int main()
{
    Solution s;
    cout << s.climbStairs(2, 2) << endl;
    return 0;
}
