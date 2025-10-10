#include <iostream>
#include <vector>
using namespace std;
/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：
输入：n = 1, k = 1
输出：[[1]]
*/
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtacking(1, n, k, path, result);
        return result;
    }
    void backtacking(const int &start, const int &n, const int &k, vector<int> &path, vector<vector<int>> &result)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            path.push_back(i);
            backtacking(i + 1, n, k, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> result = s.combine(4, 2);
    for (auto item : result)
    {
        for (auto i : item)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}