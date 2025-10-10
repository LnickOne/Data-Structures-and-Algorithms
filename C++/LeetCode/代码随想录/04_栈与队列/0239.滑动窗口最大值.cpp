#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。
滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。
示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：
输入：nums = [1], k = 1
输出：[1]
*/
class Solution
{
public:
    // 单调队列
    class MyDeque // 单调队列（从大到小）
    {
    public:
        // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        deque<int> deque;
        void pop(int value)
        {
            if (!deque.empty() && value == deque.front())
            {
                deque.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。这样就保持了队列里的数值是单调从大到小。
        void push(int value)
        {
            while (!deque.empty() && value > deque.back())
            {
                deque.pop_back();
            }
            deque.push_back(value);
        }
        // 查询当前队列里的最大值 直接返回队列前端front。
        int front()
        {
            return deque.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyDeque deque;
        vector<int> result;
        // 处理第一个窗口
        for (int i = 0; i < k; i++)
        {
            deque.push(nums[i]); // 先将前k的元素放进队列
        }
        result.push_back(deque.front()); // result记录前k的元素的最大值
        // 处理后续窗口
        for (int i = k; i < nums.size(); i++)
        {
            deque.push(nums[i]);             // 滑动窗口前加入最后面的元素
            deque.pop(nums[i - k]);          // 滑动窗口移除最前面元素
            result.push_back(deque.front()); // 记录对应的最大值
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);
    for (auto num : result)
    {
        cout << num << " ";
    }
    return 0;
}