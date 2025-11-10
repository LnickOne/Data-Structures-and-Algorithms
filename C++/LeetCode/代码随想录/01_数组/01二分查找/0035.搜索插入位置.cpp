// 二分查找前提是数组为有序数组，同时数组中无重复元素
// 时间复杂度：O(log n)
// 空间复杂度：O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        //    int left=0;
        //    int right=nums.size()-1;
        //    while (left <= right) {
        //        int mid = left + (right - left) / 2;
        //        if (nums[mid] == target)
        //            return mid;
        //        else if (nums[mid] > target)
        //            right = mid - 1;
        //        else
        //            left = mid + 1;
        //    }
        //    return left;
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }

            else
            {
                cout << "mid:" << mid << endl;
                return mid;
            }
        }
        cout << "left:" << left << endl;
        return left;
    }
};
int main()
{
    vector<int> nums_1 = {1, 3, 5, 6};
    vector<int> nums_2 = {1, 3, 5, 6};
    vector<int> nums_3 = {1, 3, 5, 6};
    int target_1 = 5;
    int target_2 = 2;
    int target_3 = 7;
    Solution s;
    cout << s.searchInsert(nums_1, target_1) << endl;
    return 0;
}