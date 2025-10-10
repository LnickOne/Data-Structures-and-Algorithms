#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        if (arr.empty())
            return 0;
        unordered_map<int, int> map;
        int result = 0;
        int left = 0;   // 滑动窗口的起始位置
        int right = 0;  // 滑动窗口的结束位置
        int length = 0; // 滑动窗口的长度
        while (right < arr.size())
        {
            while (right < arr.size() && map.find(arr[right]) == map.end())
            {
                map[arr[right]] = 1;
                right++;
            }
            length = right - left;
            result = max(result, length);
            left += 1;
            right = left;
            length = 0;
            map.clear();
        }
        return result;
        // int result = 0;
        // int left = 0;
        // int right = 0;
        // unordered_map<int, int> map;
        // while (right < arr.size())
        // {
        //     map[arr[right]]++;
        //     while (map[arr[right]] > 1)
        //     {
        //         map[arr[left]]--;
        //         left++;
        //     }
        //     result = max(result, right - left + 1);
        //     right++;
        // }
        // return result;
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {1, 2, 3, 4};
    // vector<int> nums = {3, 3, 2, 1, 3, 3, 3, 1};
    vector<int> nums = {2, 3, 4, 5};
    int ans = s.maxLength(nums);
    cout << ans << endl;
    return 0;
}