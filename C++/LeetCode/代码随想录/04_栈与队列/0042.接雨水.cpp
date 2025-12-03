/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例 2：
输入：height = [4,2,0,3,2,5]
输出：9
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 单调栈法
    int trap(vector<int> &height)
    {
         
    }
    // 暴力解法
    int trap_(vector<int> &height)
    {
        int result = 0;
        int max_left = 0;
        int max_right = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left <= right)
        {
            max_left = max(max_left, height[left]);
            max_right = max(max_right, height[right]);
            if (max_left < max_right)
            {
                result += max_left - height[left];
                left += 1;
            }
            else
            {
                result += max_right - height[right];
                right -= 1;
            }
        }
    }
};

int main()
{

    return 0;
}
