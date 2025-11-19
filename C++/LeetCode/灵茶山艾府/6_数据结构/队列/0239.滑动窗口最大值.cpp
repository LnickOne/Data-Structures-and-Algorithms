/*
给你一个整数数组 nums，有一个大小为 k
的滑动窗口从数组的最左侧移动到数组的最右侧。 你只可以看到在滑动窗口内的 k
个数字。 滑动窗口每次只向右移动一位。 返回 滑动窗口中的最大值 。 示例 1：
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
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
  // 方法一: 使用单调队列
  vector<int> maxSlidingWindow_1(vector<int> &nums, int k)
  {
    MyQueue deque;
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
      deque.push(nums[i]); // 先将前k的元素放进队列
    }
    result.push_back(deque.front()); // result 记录前k的元素的最大值
    for (int i = k; i < nums.size(); i += 1)
    {
      deque.push(nums[i]);             // 滑动窗口前加入最后面的元素
      deque.pop(nums[i - k]);          // 滑动窗口移除最前面元素
      result.push_back(deque.front()); // 记录对应的最大值
    }
    return result;
  }
  class MyQueue // 单调队列（从大到小）
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
    // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，
    // 直到push的数值小于等于队列入口元素的数值为止。
    // 这样就保持了队列里的数值是单调从大到小。
    void push(int value)
    {
      while (!deque.empty() && value > deque.back())
      {
        deque.pop_back();
      }
      deque.push_back(value);
    }
    // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
    int front() { return deque.front(); }
  };

  // 方法二: 暴力解法
  vector<int> maxSlidingWindow_2(vector<int> &nums, int k)
  {
    vector<int> result;
    int max_val;
    int left = 0;   // 滑动窗口的起始位置
    int right = 0;  // 滑动窗口的结束位置
    int length = 0; // 滑动窗口的长度
    while (right < nums.size() - k + 1)
    {
      if (length != k)
      {
        right += k;
        length += k;
      }
      if (left + k < nums.size() + 1)
      {
        max_val = *max_element(nums.begin() + left, nums.begin() + right);
      }
      result.push_back(max_val);
      left += 1;    // 滑动窗口的起始位置每次向右移动一位
      right = left; // 滑动窗口的结束位置跟随起始位置
      length = 0;   // 滑动窗口做完需求操作后长度归0
    }
    return result;
  }
};

int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
  int k1 = 5000;
  Solution s;
  s.maxSlidingWindow_2(nums, k);

  return 0;
}