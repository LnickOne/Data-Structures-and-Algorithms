#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
你需要按照以下要求，给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
示例 1：
输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
示例 2：
输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
*/
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> left(ratings.size(), 1);  // 左边小孩
        vector<int> right(ratings.size(), 1); // 右边小孩
        vector<int> candy(ratings.size());    // 分配糖果
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;
        }
        for (int i = 0; i < ratings.size(); i++)
            candy[i] = max(left[i], right[i]);
        return accumulate(candy.begin(), candy.end(), 0);
    }
};

int main()
{
    vector<int> nums = {1, 0, 2};

    Solution sol;
    cout << sol.candy(nums);
}