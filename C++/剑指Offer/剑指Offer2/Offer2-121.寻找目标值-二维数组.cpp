/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)
题目描述
m*n 二维数组 plants, 每行从左到右递增, 每列从上到下递增。判断是否存在目标值 target。
题目样例
示例1
- 输入: plants=[[2,3,6,8],[4,5,8,9],[5,9,10,12]], target=8
- 输出: true
示例2
- 输入: plants=[[1,3,5],[2,5,7]], target=4
- 输出: false
题目思考
1. 如何利用行列递增条件优化?
解决方案
思路
- 从左下角出发: 当前值 > target 则上移 (r--), < target 则右移 (c++)
- 每次排除一行或一列, O(R+C) 线性遍历
复杂度
- 时间复杂度 O(R+C): 每次行或列减少 1
- 空间复杂度 O(1): 常数空间
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findTargetIn2DPlants(vector<vector<int>> &plants, int target)
    {
        if (plants.empty() || plants[0].empty())
            return false;
        int rows = (int)plants.size(), cols = (int)plants[0].size();
        int r = rows - 1, c = 0;
        while (r >= 0 && c < cols)
        {
            if (plants[r][c] == target)
                return true;
            else if (plants[r][c] > target)
                --r;
            else
                ++c;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    vector<vector<int>> p1 = {{2, 3, 6, 8}, {4, 5, 8, 9}, {5, 9, 10, 12}};
    cout << sol.findTargetIn2DPlants(p1, 8) << endl; // true
    vector<vector<int>> p2 = {{1, 3, 5}, {2, 5, 7}};
    cout << sol.findTargetIn2DPlants(p2, 4) << endl; // false
    return 0;
}
