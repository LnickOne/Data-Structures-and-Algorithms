/*
给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。
让我们回顾一下，如果 arr 满足下述条件，那么它是一个山脉数组：
arr.length >= 3
在 0 < i < arr.length - 1 条件下，存在 i 使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
示例 1：
输入：arr = [2,1]
输出：false
示例 2：
输入：arr = [3,5,5]
输出：false
示例 3：
输入：arr = [0,3,2,1]
输出：true
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
            return false;
        int left = 0;
        int right = arr.size() - 1;
        while (left < arr.size() - 1 && arr[left] < arr[left + 1]) // 注意防止越界
            left++;
        while (right > 0 && arr[right] < arr[right - 1]) // 注意防止越界
            right--;
        if (left == right && left != 0 && right != arr.size() - 1) // 如果left或者right都在起始位置，说明不是山峰
            return true;
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << s.validMountainArray(arr) << endl;
    return 0;
}