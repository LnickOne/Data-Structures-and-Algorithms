#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定数组arr，arr中所有的值都为正整数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，
再给定一个aim，代表要找的钱数，求组成aim的最少货币数。
如果无解，请返回-1.
[5,2,3],20
4
[5,2,3],0
0
[3,5],2
-1
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    2. 确定递推关系
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int minMoney(vector<int> &arr, int aim)
    {
        int backpack_capacity = aim;
        vector<int> dp(backpack_capacity + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < arr.size(); i++) // 遍历物品
        {
            for (int j = arr[i]; j <= backpack_capacity; j++) // 遍历背包
            {
                if (dp[j - arr[i]] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - arr[i]] + 1);
            }
        }
        if (dp[backpack_capacity] == INT_MAX)
            return -1;
        else
            return dp[backpack_capacity];
    }
};

int main()
{
    vector<int> arr{5, 2, 3};
    int aim = 20;
    Solution s;
    cout << s.minMoney(arr, aim) << endl;
    return 0;
}