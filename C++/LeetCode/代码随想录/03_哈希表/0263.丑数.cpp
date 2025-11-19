/*
丑数 就是只包含质因数 2、3 和 5 的 正 整数。
给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
示例 1：
输入：n = 6
输出：true
解释：6 = 2 × 3
示例 2：
输入：n = 1
输出：true
解释：1 没有质因数。
示例 3：
输入：n = 14
输出：false
解释：14 不是丑数，因为它包含了另外一个质因数 7 。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        unordered_map<int, int> map = {{2, 0}, {3, 0}, {5, 0}};
        vector<int> factors = primeFactorize(n);
        for (int &i : factors)
        {
            if (map.find(i) == map.end())
                return false;
        }
        return true;
    }

    vector<int> primeFactorize(int n) // 质因数分解
    {
        vector<int> result;
        for (int i = 2; i * i <= n; ++i)
        {
            while (n % i == 0)
            {
                result.push_back(i);
                n = n / i;
            }
        }
        if (n > 1)
        { // 如果n大于1，说明n本身是一个质数
            result.push_back(n);
        }
        return result;
    }
};