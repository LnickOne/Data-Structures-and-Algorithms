#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
动态规划五部曲
1. 确定dp数组以及下标的含义
dp[i]表示跳到第i个台阶的方法数
2. 确定递推关系
dp[i] = dp[i-1] + dp[i-2]
3. 确定初始值
dp[0] = 1;
dp[1] = 1;
4. 确定遍历顺序
从左到右，从上到下
for (int i = 2; i <= num; i++)
5. 举例推导dp数组
*/
class Solution
{
public:
    int trainWays(int num)
    {
        if (num <= 1)
            return 1;
        vector<int> dp(num + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= num; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        return dp[num];
    }
};

int main()
{
    Solution s;
    cout << s.trainWays(5) << endl;
    return 0;
}