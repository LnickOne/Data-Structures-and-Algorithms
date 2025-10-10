/*
二分查找前提是数组为有序数组，同时数组中无重复元素
时间复杂度：O(log n)
空间复杂度：O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 左闭右开
        // int left = 0;
        // int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
        // while (left < right)
        // {
        //     // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
        //     int mid = left + (right - left) / 2;
        //     if (nums[mid] > target)
        //     {
        //         right = mid; // target 在左区间，在[left, mid)中
        //     }
        //     else if (nums[mid] < target)
        //     {
        //         left = mid + 1; // target 在右区间，在[mid + 1, right)中
        //     }
        //     else
        //     {               // nums[mid] == target
        //         return mid; // 数组中找到目标值，直接返回下标
        //     }
        // }
        // 左闭右闭
        int result = -1;
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，即：[left, right]
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                right = mid - 1; // target 在左区间，在[left, mid - 1]中
            if (nums[mid] < target)
                left = mid + 1; // target 在右区间，在[mid + 1, right]中
        }
        return result; // 未找到目标值;
    }
};

int main()
{
    vector<int> nums_1 = {-1, 0, 3, 5, 9, 12};
    int target_1 = 9;

    int o = Solution().search(nums_1, target_1);
    cout << o << endl;

    return 0;
}