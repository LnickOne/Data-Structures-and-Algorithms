/*
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
示例 1：
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
示例 2：
输入：n = 2
输出：false
*/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while (true)
        {
            int sum = getSum(n);
            if (sum == 1)
                return true;
            if (set.find(sum) != set.end()) // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
                return false;
            if (set.find(sum) == set.end()) // 如果这个sum没有出现过，插入sum
                set.insert(sum);
            n = sum;
        }
        return true;
    }
    int getSum(int n)
    {
        string str_n = to_string(n);
        int sum = 0;
        for (const char &ch : str_n)
            sum = sum + pow(ch - '0', 2);
        return sum;
    }
};

int main()
{
    int n_1 = 19;
    int n_2 = 2;
    int n_3 = 7;
    int n_4 = 1111111;
    cout << Solution().isHappy(n_4) << endl;
    return 0;
}