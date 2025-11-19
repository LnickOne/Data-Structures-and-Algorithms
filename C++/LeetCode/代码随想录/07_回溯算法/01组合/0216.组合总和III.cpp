#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
只使用数字1到9
每个数字 最多使用一次
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
解释:
1 + 2 + 4 = 7
没有其他符合的组合了。
示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。
示例 3:
输入: k = 4, n = 1
输出: []
解释: 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
*/
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(1, k, n, path, result);
        return result;
    }
    void backtracking(const int &start, const int &k, const int &n, vector<int> &path, vector<vector<int>> &result)
    {
        if (path.size() == k && accumulate(path.begin(), path.end(), 0) > n)
            return;
        if (path.size() == k && accumulate(path.begin(), path.end(), 0) == n)
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            path.push_back(i);
            backtracking(i + 1, k, n, path, result);
            path.pop_back();
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> result = s.combinationSum3(3, 7);
    vector<vector<int>> result1 = s.combinationSum3(3, 9);
    vector<vector<int>> result2 = s.combinationSum3(4, 1);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}