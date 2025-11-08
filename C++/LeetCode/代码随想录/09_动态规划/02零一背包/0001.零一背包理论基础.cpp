#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
01背包的核心思想
一维数组遍历
for(int i = 0; i < weight.size(); i+=1) // 遍历物品
{
    for(int j = backpack_capacity; j >= weight[i]; j-=1)//遍历背包容量 01背包是从背包的容量开始倒序遍历
    {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
二维数组遍历
for (int i = 1; i < weight.size(); i++)
    for (int j = 0; j <= backpack_capacity; j++)
        if (j >= weight[i]) // 如果背包容量能装的下物品i
        {
            dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - weight[i]] + values[i]);//取一个最大值
        }
        else // 否则dp[i][j]继承上一个装不下物品i的最大价值
        {
            dp[i][j] = dp[i - 1][j];
        }
01背包二维dp数组的两个for遍历的先后循序是可以颠倒。
但是一维dp数组的两个for循环先后循序一定是先遍历物品，再遍历背包容量。不可以先遍历背包容量再遍历物品。
*/
class Solution
{
public:
    /*
     01背包一维数组
     动态规划五部曲
     1. 确定dp数组以及下标的含义
     dp[j]：表示容量为j的背包,所能获取最大的价值为dp[j]
     2. 确定递推关系
     一. 不放物品i，背包容量为j所能装的最大价值是dp[j],因此是d[j]
     二. 放物品i，背包容量为j所能装的最大价值是容量j的背包减去物品i的重量的所能获取的最大价值,再加上物品i的价值,即dp[j-weight[i]],加上value[i]
     dp[j-weight[i]]表示：容量为j-weight[i]的背包,所背的物品价值可以最大为dp[j-weight[i]]。
     value[i]表示物品i的价值,即放入物品i的价值为value[i]。
     dp[j] = max(dp[j], dp[j - weight[i]] + value[i]) 两者取最大值
     3. 确定初始值
     关于初始化,一定要和dp数组的定义吻合,否则到递推公式的时候就会越来越乱。
     dp[j]表示：容量为j的背包,所背的物品价值可以最大为dp[j]。
     dp[0]初始化是0,因为背包容量为0所背的物品的最大价值是0。
     dp数组除了下标0的位置,初始为0,其他下标应该初始化多少呢？
     递归公式：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
     dp数组在推导的时候一定是取价值最大的数,如果题目给的价值都是正整数那么非0下标都初始化为0就可以了。
     这样才能让dp数组在递归公式的过程中取的最大的价值,而不是被初始值覆盖了。
     假设物品价值都是大于0的,所以dp数组初始化的时候,都初始为0就可以了。
     4. 确定遍历顺序
     for (int i = 0; i < weight.size(); i++)                  // 遍历物品
         for (int j = backpack_capacity; j >= weight[i]; j--) // 遍历背包
             dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
     5. 举例推导dp数组
     */
    void backpack(vector<int> weight, vector<int> values, int backpack_capacity)
    {
        vector<int> dp_1(backpack_capacity + 1, 0);                 // 初始化为0
        for (int i = 0; i < weight.size(); i += 1)                  // 遍历物品
            for (int j = backpack_capacity; j >= weight[i]; j -= 1) // 一维数组遍历是从背包的总重量开始,并使用倒序是因为保证每个物品都只被添加过一次
            {                                                       // if j>=weight[i]藏在for循环里
                dp_1[j] = max(dp_1[j], dp_1[j - weight[i]] + values[i]);
            }
        cout << "一维数组dp[j]" << " " << endl;
        for (int j = 0; j <= backpack_capacity; j++)
        {
            cout << dp_1[j] << " ";
        }
        cout << endl;
        /*
        01背包二维数组
        动态规划五部曲
        1. 确定dp数组以及下标的含义
        dp[i][j]表示任取下标0-i之间的物品,放进容量为j的背包,所能获取最大的价值多少
        2. 确定递推关系
        一. 不放物品i,背包容量为j所能装的最大价值是dp[i-1][j],i-1表示任取[0,i-1]个物品但不包含i这个物品,递推关系为dp[i][j]=dp[i-1][j]
        二. 放物品i,背包容量为j所能装的最大价值是这个容量j的背包减去物品i的容量所能装的最大价值,并且加上物品i的价值
        即dp[i-1][j-weight[i]]的最大价值加上value[i],递推关系为dp[i][j]=dp[i-1][j-weight[i]]+values[i]
        求最大价值需要判断一个max,因此二维数组
        dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
        3. 确定初始值
        for (int i = 0; i < weight.size(); i+=1)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= backpack_capacity; j+=1)
        {
            if (j >= weight[0])// 如果背包容量装的下物品0,那么背包的最大价值就初始化为物品0的价值
                dp[0][j] = values[0];
        }
        4. 确定遍历顺序
        for (int i = 1; i < weight.size(); i+=1)
            for (int j = 0; j <= backpack_capacity; j+=1)
                if (j >= weight[i]) // 如果背包容量能装的下物品i
                {
                    dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - weight[i]] + values[i]);//取一个最大值
                }
                else // 否则dp[i][j]继承上一个装不下物品i的最大价值
                {
                    dp[i][j] = dp[i - 1][j];
                }
        5. 举例推导dp数组
        */
        vector<vector<int>> dp(weight.size(), vector<int>(backpack_capacity + 1)); // 创建一个二维dp数组,i表示物品的个数,j表示背包容量
        for (int i = 0; i < weight.size(); i += 1)                                 // 初始化dp[i][j]数组
        {
            dp[i][0] = 0; // 如果背包容量j为0的话,即dp[i][0],无论是选取哪些物品,背包价值总和一定为0。
        }
        for (int j = 0; j <= backpack_capacity; j += 1) // dp[0][j],即：i为0,存放物品0的时候,各个容量的背包所能存放的最大价值。
        {
            if (j >= weight[0]) // 如果背包容量装的下物品0,那么背包所能存放的最大价值就初始化为物品0的价值
            {
                dp[0][j] = values[0];
            }
        }
        for (int i = 1; i < weight.size(); i += 1)
        {
            for (int j = 0; j <= backpack_capacity; j += 1)
            {
                if (j >= weight[i]) // 如果背包容量装的下物品i,就取一个最大值
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + values[i]);
                }
                else // 否则,dp[i][j]继承上一个装不下物品i的最大价值
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << "二维数组dp[i][j]" << " " << endl;
        for (int i = 0; i < weight.size(); i += 1)
        {
            for (int j = 0; j <= backpack_capacity; j += 1)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int backpack_capacity = 6;               // 背包容量
    vector<int> weight = {2, 2, 3, 1, 5, 2}; // 每件物品重量
    vector<int> values = {2, 3, 1, 5, 4, 3}; // 每件物品价值
    Solution s;
    s.backpack(weight, values, backpack_capacity);
};
