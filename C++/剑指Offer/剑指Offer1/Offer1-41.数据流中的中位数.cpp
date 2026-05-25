/*
> 题目难度: 困难
> [原题链接](https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/)
题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
例如，
- [2,3,4]  的中位数是 3
- [2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：
- void addNum(int num) - 从数据流中添加一个整数到数据结构中。
- double findMedian() - 返回目前所有元素的中位数。
- 最多会对 addNum、findMedia 进行 50000 次调用。
题目样例
示例
输入
`["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]`
`[[],[1],[2],[],[3],[]]`
输出
`[null,null,null,1.50000,null,2.00000]`
题目思考
1. 观察数据规模, 会有 5W 次调用, 那么意味着每次调用的平均时间不能超过 O(N), 不然就需要 5W*5W 的数量级, 有什么数据结构可以做到每次调用的时间复杂度小于 O(N) 呢?
解决方案
思路
- 根据中位数性质, 它要么是偶数长度数组的两个中间值的平均数, 要么是奇数长度数组的最中间的值
- 考虑到每次调用复杂度要小于 O(N), 显然 O(1)是不可能的, 我们没办法只根据当前插入的值直接判断更新后的中位值是什么, 必须通过一些扫描和判断
- 那么我们尝试 O(logN)复杂度的数据结构, 注意到中间值左边的部分一定是小于中间值的, 而右边的部分一定是大于中间值的, 是有一定的有序性的
- 我们可以利用这一点, 构造两个堆:
  - 左边是一个大顶堆, 存放所有小于等于中间值的数(奇数长度的话, 堆顶就是中间值)
  - 右边是一个小顶堆, 存放所有大于等于中间值的数(因为可能有很多重复元素)
- **查询中位数**
  - 当前元素个数为奇数时, 直接返回左堆顶
  - 当前元素个数为偶数时, 返回左堆顶和右堆顶的平均值
- **插入新元素**
  - 先将 num 插入大顶堆, 再将大顶堆顶移入小顶堆, 保证左堆元素均不大于右堆元素
  - 若小顶堆元素数量多于大顶堆, 将小顶堆顶移回大顶堆, 保证大顶堆元素个数 >= 小顶堆
复杂度
- 时间复杂度 `O(logN)`
  - 每次调用只需要常数次堆操作, 复杂度为 O(logN)
- 空间复杂度 `O(N)`
  - 两个堆共需要存 N 个元素
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder
{
public:
  // 大顶堆: 存放较小的一半元素
  priority_queue<int> maxHeap;
  // 小顶堆: 存放较大的一半元素
  priority_queue<int, vector<int>, greater<int>> minHeap;

  MedianFinder()
  {
  }

  void addNum(int num)
  {
    // 先加入大顶堆
    maxHeap.push(num);
    // 将大顶堆顶移入小顶堆, 保证左侧均不大于右侧
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    // 若小顶堆比大顶堆多, 将小顶堆顶移回大顶堆
    if (minHeap.size() > maxHeap.size())
    {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double findMedian()
  {
    if (maxHeap.size() == minHeap.size())
    {
      return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    else
    {
      return maxHeap.top();
    }
  }
};

int main()
{
  MedianFinder mf;
  mf.addNum(1);
  mf.addNum(2);
  cout << mf.findMedian() << endl; // 1.5
  mf.addNum(3);
  cout << mf.findMedian() << endl; // 2

  MedianFinder mf2;
  mf2.addNum(2);
  mf2.addNum(3);
  mf2.addNum(4);
  cout << mf2.findMedian() << endl; // 3

  return 0;
}
