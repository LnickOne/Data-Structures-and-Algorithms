/* > 题目难度: 简单
> [原题链接](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)
题目描述
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入 4、5、1、6、2、7、3、8 这 8 个数字，则最小的 4 个数字是 1、2、3、4。
- 0 <= k <= arr.length <= 10000
- 0 <= arr[i] <= 10000
题目样例
示例
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
题目思考
1. 最简单的方案是什么?
2. 如何一步步优化?
解决方案
方案 1
思路
- 一个最简单的思路相信大家都很容易想到, 那就是排序然后取前 k 个, 一行代码完事..
- 但这种方案时间复杂度比较差, 特别是当 N 特别大的时候, 所以还是有很多可以优化的地方
复杂度
- 时间复杂度 `O(NlogN)`
  - 需要排序
- 空间复杂度 `O(1)`
  - 不需要额外空间(原地排序时)
方案 2
思路
- 维护一个大小为 k 的最大堆, 然后从头开始遍历:
  - 当堆中元素数目不足 k 的时候, 直接加入堆中
  - 否则要判断当前元素与堆顶大小, 如果当前元素更小的话, 就要拿它替代堆顶元素
- 这样最终堆中的元素就是最小的 k 个元素, **因为更大的元素在之前的遍历中就被替换出去了, 或者根本不会被加入堆中**
复杂度
- 时间复杂度 `O(NlogK)`
  - 只需要遍历数组一遍, 遍历的时候需要插入堆, 插入的时间复杂度为 `O(logK)`
- 空间复杂度 `O(K)`
  - 堆空间的消耗
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (k == 0)
            return {};

        // 使用大小为 k 的最大堆
        priority_queue<int> maxheap;
        for (int a : arr)
        {
            // 堆元素数目小于k, 直接入堆
            if ((int)maxheap.size() < k)
            {
                maxheap.push(a);
            }
            else if (a < maxheap.top())
            {
                // 当前元素小于堆顶, 替换堆顶
                maxheap.pop();
                maxheap.push(a);
            }
        }

        vector<int> res;
        while (!maxheap.empty())
        {
            res.push_back(maxheap.top());
            maxheap.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;

    // 示例: arr = [3,2,1], k = 2 => [1,2]
    vector<int> arr1 = {3, 2, 1};
    vector<int> res1 = s.getLeastNumbers(arr1, 2);
    cout << "输入 [3,2,1], k=2 => [";
    for (int i = 0; i < (int)res1.size(); i++)
    {
        if (i)
            cout << ",";
        cout << res1[i];
    }
    cout << "]" << endl;

    // 示例: arr = [4,5,1,6,2,7,3,8], k = 4 => [1,2,3,4]
    vector<int> arr2 = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> res2 = s.getLeastNumbers(arr2, 4);
    cout << "输入 [4,5,1,6,2,7,3,8], k=4 => [";
    for (int i = 0; i < (int)res2.size(); i++)
    {
        if (i)
            cout << ",";
        cout << res2[i];
    }
    cout << "]" << endl;

    return 0;
}
