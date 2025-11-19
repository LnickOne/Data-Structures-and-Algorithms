/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
示例 1：
输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
示例 2：
输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int result = 0;
        unordered_map<int, int> map;
        for (int n1 : nums1)
            for (int n2 : nums2)
                map[n1 + n2]++;
        for (int n3 : nums3)
            for (int n4 : nums4)
                if (map.find(0 - n3 - n4) != map.end())
                    result += map[0 - n3 - n4];
        return result;
    }
};

int main()
{
    vector<int> nums1 = {0}, nums2 = {0}, nums3 = {0}, nums4 = {0};
    Solution s;
    int result = s.fourSumCount(nums1, nums2, nums3, nums4);
    cout << result << endl;
    vector<int> nums5 = {1, 2}, nums6 = {-2, -1}, nums7 = {-1, 2}, nums8 = {0, 2};
    int result2 = s.fourSumCount(nums5, nums6, nums7, nums8);
    cout << result2 << endl;
    return 0;
}