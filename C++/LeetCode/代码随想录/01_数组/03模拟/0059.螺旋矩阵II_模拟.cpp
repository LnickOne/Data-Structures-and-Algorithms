#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));
        int start_row = 0;
        int start_col = 0;
        int row = 0;
        int col = 0;
        int offset = 1;
        int count = 1;
        int loop = 1;
        while (loop <= n / 2)
        {
            for (col = start_col; col < n - offset; ++col) // 上边从左往右遍历
            {
                result[start_row][col] = count;
                ++count;
            }
            for (row = start_row; row < n - offset; ++row) // 右边从上往下遍历
            {
                result[row][col] = count;
                count += 1;
            }
            for (; col > start_col; --col) // 下边从右往左遍历
            {
                result[row][col] = count;
                ++count;
            }
            for (; row > start_row; --row) // 左边从下往上遍历
            {
                result[row][col] = count;
                ++count;
            }
            ++start_row;
            ++start_col;
            ++loop;
            ++offset;
        }
        if (n % 2 == 1)
            result[start_row][start_col] = count;
        return result;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> result = s.generateMatrix(4);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> result1 = s.generateMatrix(5);
    for (int i = 0; i < result1.size(); i++)
    {
        for (int j = 0; j < result1[i].size(); j++)
        {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}