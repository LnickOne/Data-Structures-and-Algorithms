/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/jBjn9C/)
题目描述
设计找到数据流中第 k 大元素的类 KthLargest:
- KthLargest(int k, int[] nums): 用整数 k 和整数流 nums 初始化
- int add(int val): 将 val 插入数据流后返回第 k 大的元素
题目样例
示例1
- 输入: ["KthLargest","add","add","add","add","add"] [[3,[4,5,8,2]],[3],[5],[10],[9],[4]]
- 输出: [null,4,5,5,8,8]
题目思考
1. 可以使用什么数据结构?
解决方案
思路
- 维护大小为 k 的最小堆: 堆中保存当前最大的 k 个元素, 堆顶即为第 k 大
- 每次 add 时将元素加入堆, 若堆大小超过 k 则弹出堆顶 (最小值)
复杂度
- 时间复杂度 O(logk): 每次 add 操作对最多 k 个元素的堆进行操作
- 空间复杂度 O(k): 最小堆存储最多 k 个元素
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (int x : nums) add(x);
    }
    int add(int val)
    {
        pq.push(val);
        if ((int)pq.size() > k) pq.pop();
        return pq.top();
    }
};

int main()
{
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kl(3, nums);
    cout << kl.add(3) << endl;  // 4
    cout << kl.add(5) << endl;  // 5
    cout << kl.add(10) << endl; // 5
    cout << kl.add(9) << endl;  // 8
    cout << kl.add(4) << endl;  // 8
    return 0;
}
