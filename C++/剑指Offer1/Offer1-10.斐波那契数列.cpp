#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
动态规划五部曲
1. 确定dp数组以及下标的含义
2. 确定递推关系
3. 确定初始值
4. 确定遍历顺序
5. 举例推导dp数组
*/
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return dp[n];
    }
};

int main()
{
    cout << Solution().fib(5) << endl;
    cout << Solution().fib(10) << endl;
    return 0;
}
