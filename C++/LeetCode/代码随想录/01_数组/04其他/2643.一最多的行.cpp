/*
给你一个大小为 m x n 的二进制矩阵 mat ，请你找出包含最多 1 的行的下标（从 0 开始）以及这一行中 1 的数目。
如果有多行包含最多的 1 ，只需要选择 行下标最小 的那一行。
返回一个由行下标和该行中 1 的数量组成的数组。

示例 1：
输入：mat = [[0,1],[1,0]]
输出：[0,1]
解释：两行中 1 的数量相同。所以返回下标最小的行，下标为 0 。该行 1 的数量为 1 。所以，答案为 [0,1] 。

示例 2：
输入：mat = [[0,0,0],[0,1,1]]
输出：[1,2]
解释：下标为 1 的行中 1 的数量最多。该行 1 的数量为 2 。所以，答案为 [1,2] 。

示例 3：
输入：mat = [[0,0],[1,1],[0,0]]
输出：[1,2]
解释：下标为 1 的行中 1 的数量最多。该行 1 的数量为 2 。所以，答案为 [1,2] 。
*/
#include <vector>
#include <iostream>
#include <map>
#include <climits>
using namespace std;
class Solution
{
public:
    // vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    // {
    //     if (mat.empty())
    //         return {};
    //     vector<int> result;
    //     int row = mat.size();
    //     int col = mat[0].size();
    //     int max_count = 0;
    //     int min_index = 0;
    //     for (int i = 0; i < row; ++i)
    //     {
    //         int count = 0;
    //         for (int j = 0; j < col; ++j)
    //         {
    //             if (mat[i][j] == 1)
    //             {
    //                 ++count;
    //             }
    //         }
    //         if (max_count < count || (min_index > i && count == max_count))
    //         {
    //             max_count = count;
    //             min_index = i;
    //         }
    //     }
    //     result = {min_index, max_count};
    //     return result;
    // }
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        if (mat.empty())
            return {};
        multimap<int, int,greater<int>> countMap;
        int row = mat.size();
        int col = mat[0].size();
        for (int i = 0; i < row; ++i)
        {
            int count = 0;
            for (int j = 0; j < col; ++j)
            {
                if (mat[i][j] == 1)
                {
                    ++count;
                }
            }
            countMap.insert({count, i});
        }
        int max_count = countMap.begin()->first;
        int min_index = INT_MAX;
        for (auto it = countMap.begin(); it != countMap.end() && it->first == max_count; ++it)
        {
            if (it->second < min_index)
            {
                min_index = it->second;
            }
        }
        return {min_index, max_count};
    }
};
int main()
{
    vector<vector<int>> mat = {{0, 1}, {1, 0}};
    Solution s;
    vector<int> result = s.rowAndMaximumOnes(mat);
    for (const auto &iter : result)
    {
        cout << iter << endl;
    }
    return 0;
}