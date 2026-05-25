/* > 题目难度: 困难

> [原题链接](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)

题目描述

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

0 <= 数组长度 <= 50000

题目样例

示例

- 输入: [7,5,6,4]
- 输出: 5

题目思考

1. 如何批量得到逆序对?

解决方案

思路

- 一个比较容易想到的思路是双重循环, 暴力求逆序对, 但这样时间复杂度是 O(N^2), 根据数据规模肯定超时, 如何进行优化呢?
- 如果我们能将问题进行分解, 先求出数组左右两部分的逆序对数目, 最后再一次遍历将分属两部分的逆序对(也即第一个数在左半部分, 第二个数在右半部分)也求出来并累加在一起, 这样就能优化时间复杂度到 O(NlogN), 这就是分治法的思想
- 此时关键在于如何一次遍历就求得分属两部分的逆序对呢? 如果左右两部分是有序的就很好办了, 可以利用归并排序的思路, 双指针遍历, 哪边小就把哪边加入结果数组中. **如果是右侧小的话就意味着左侧剩余的数字都和当前右侧数字构成逆序对, 将对应的数目加入结果中即可**.
- 而左右部分有序正好也是归并排序的结果, 所以整个思路就是在归并排序的基础上加上逆序对的统计
- 下面代码对必要的步骤有详细的解释, 方便大家理解

复杂度

- 时间复杂度 O(NlogN): 使用了归并排序, 时间复杂度是(`N+(N/2)*2+(N/4)*4+...+1*N = NlogN`, 因为一共 `logN` 个乘积)
- 空间复杂度 O(N): 归并排序需要用到临时数组, 长度为 N
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        long long cnt = 0;
        mergeSort(nums, 0, (int)nums.size() - 1, cnt);
        return (int)cnt;
    }

private:
    void mergeSort(vector<int> &nums, int left, int right, long long &cnt)
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, cnt);
        mergeSort(nums, mid + 1, right, cnt);
        merge(nums, left, mid, right, cnt);
    }

    void merge(vector<int> &nums, int left, int mid, int right, long long &cnt)
    {
        vector<int> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                tmp[k++] = nums[i++];
            }
            else
            {
                // nums[i] > nums[j]: 左侧 i..mid 的所有元素都与 nums[j] 构成逆序对
                cnt += (long long)(mid - i + 1);
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid)
            tmp[k++] = nums[i++];
        while (j <= right)
            tmp[k++] = nums[j++];
        for (int x = 0; x < k; x++)
        {
            nums[left + x] = tmp[x];
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {7, 5, 6, 4};
    cout << sol.reversePairs(nums1) << endl; // 5

    vector<int> nums2 = {1, 3, 2, 3, 1};
    cout << sol.reversePairs(nums2) << endl; // 4

    vector<int> nums3 = {};
    cout << sol.reversePairs(nums3) << endl; // 0

    vector<int> nums4 = {1, 2, 3, 4, 5};
    cout << sol.reversePairs(nums4) << endl; // 0

    return 0;
}
