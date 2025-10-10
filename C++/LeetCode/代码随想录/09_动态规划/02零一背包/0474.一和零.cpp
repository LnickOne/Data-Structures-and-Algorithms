#include <vector>
#include <iostream>
using namespace std;
/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
示例 1：
输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，
因为它含 4 个 1 ，大于 n 的值 3 。
示例 2：
输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]：表示最多有i个0和j个1的strs的最大子集的长度为dp[i][j]。
    dp[i][j]：m个0和n个1看做一种容器，装满这个容器最多有多少个元素.
    这个背包有两个维度，10是一个物品，0001是一个物品
    所以需要定义二维数组dp[i][j],i表示m,j表示n
    dp[i][j]：表示容量为[i,j]的背包最多能装多少个物品
    装不下物品ij,dp数组的值是dp[i][j].
    装得下物品ij,dp数组的值是dp[i-zero][j-one]+1
    两者取最大值
    dp数组求的是最大物品有多少个
    2. 确定递推关系
    物品的重量是多少个0和1，物品的个数是1，
    dp[i][j] = max(dp[i][j],dp[i-zero][j-one]+1)
    3. 确定初始值
    全部初始为0，不会被更大的值覆盖
    4. 确定遍历顺序
    5. 举例推导dp数组
     */
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int backpack_zero = m;
        int backpack_one = n;
        vector<vector<int>> dp(backpack_zero + 1, vector<int>(backpack_one + 1, 0)); // 创建一个二维dp数组,i表示0的个数,j表示1的个数
        for (string str : strs)                                                      // 遍历物品,strs 数组里的元素就是物品，每个物品都是一和零的集合体
        {
            int weight_zero = 0;
            int weight_one = 0;
            for (char ch : str)
            {
                if (ch == '0')
                    weight_zero++;
                if (ch == '1')
                    weight_one++;
            }
            for (int i = m; i >= weight_zero; i -= 1) // 遍历背包，这个背包是二维的，分别放0和1,0和1又构成一个统一的物品。通常01背包是一维dp[j]
            {
                for (int j = n; j >= weight_one; j -= 1)
                    dp[i][j] = max(dp[i][j], dp[i - weight_zero][j - weight_one] + 1);
            }
        }
        return dp[backpack_zero][backpack_one];
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << s.findMaxForm(strs, m, n) << endl;
}