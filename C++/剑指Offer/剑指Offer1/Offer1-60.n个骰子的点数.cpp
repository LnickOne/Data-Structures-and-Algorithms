/*
> 题目难度: 简单
> [原题链接](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/)
题目描述
把 n 个骰子扔在地上，所有骰子朝上一面的点数之和为 s。输入 n，打印出 s 的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
- 1 <= n <= 11
题目样例
示例
- 输入: 1
- 输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
- 输入: 2
- 输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
题目思考
1. 可以根据 n 个骰子的概率推导出 n+1 个骰子的概率吗
解决方案
思路
- 分析题目, 先从 1 个骰子的最简单情况出发, 显然点数为 1~6 的概率都是 1/6
- 那如果是 2 个骰子呢? 假设第一个骰子点数为 1, 第二个可以是 1~6, 两者之和就是 2~7; 而如果第一个点数为 2, 那么两者之和就是 3~8, 以此类推
- 显然 2 个骰子点数之和为 2 的概率是`(1/6)*(1/6)=1/36`, 只有 1+1 一种情况; 而点数之和为 3 的概率是`1/36+1/36=1/18`, 有 1+2 和 2+1 两种情况, 以此类推
- 所以如果我们使用一个字典来保存当前骰子数 n 的每个点数之和的概率, 即键值对是`{点数和:概率}`, 那么对于 n+1 而言, 我们只需要对每个点数之和加上 1~6 作为新的点数之和, 将原有概率乘以 1/6 累加到新的点数和对应的概率上即可
- 最后只需要根据有效点数之和从小到大, 将字典中的值依次存入最终结果中
- 对于 n 个骰子而言, 其点数之和最小为 n (每个骰子点数都是 1), 最大为 `6*n` (每个骰子点数都是 6)
- 下面代码对必要的步骤有详细的解释, 方便大家理解
复杂度
- 时间复杂度 O(N^2): 两层循环, 外层遍历 N 个数, 内层遍历 `5N*6` 个数
- 空间复杂度 O(N): 字典中需要存 5N 个键值对
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<double> statisticsProbability(int num)
    {
        // dp[s] = probability that sum is s with current number of dice
        vector<double> dp(6 * num + 1, 0);
        // init: 1 die
        for (int v = 1; v <= 6; v++)
            dp[v] = 1.0 / 6;
        for (int i = 2; i <= num; i++)
        {
            vector<double> ndp(6 * num + 1, 0);
            for (int s = i - 1; s <= 6 * (i - 1); s++)
            {
                if (dp[s] == 0)
                    continue;
                for (int v = 1; v <= 6; v++)
                    ndp[s + v] += dp[s] / 6;
            }
            dp = ndp;
        }
        vector<double> res;
        for (int s = num; s <= 6 * num; s++)
            res.push_back(dp[s]);
        return res;
    }
};

int main()
{
    Solution s;
    auto res = s.statisticsProbability(1);
    for (double x : res)
        cout << x << " ";
    cout << endl;
    res = s.statisticsProbability(2);
    for (double x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
