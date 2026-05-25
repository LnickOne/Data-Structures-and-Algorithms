/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/H8086Q/)
题目描述
实现 RecentCounter 类:
- RecentCounter(): 初始化计数器, 请求数为 0
- int ping(int t): 在时间 t 添加新请求, 返回过去 3000 毫秒内 [t-3000,t] 的请求数
题目样例
示例1
- 输入: ["RecentCounter","ping","ping","ping","ping"] [[],[1],[100],[3001],[3002]]
- 输出: [null,1,2,3,3]
题目思考
1. 可以使用什么数据结构模拟整个过程?
解决方案
思路
- 用 deque 维护时间窗口内的请求
- 每次 ping 时将 t 加入队尾, 然后将队头所有早于 t-3000 的请求弹出
- 返回队列长度
复杂度
- 时间复杂度 O(1): 每个请求最多入队出队各一次, 均摊 O(1)
- 空间复杂度 O(N): 双端队列最多存全部 N 个元素
 */
#include <iostream>
#include <deque>
using namespace std;

class RecentCounter
{
    deque<int> dq;
public:
    int ping(int t)
    {
        dq.push_back(t);
        while (dq.front() < t - 3000)
            dq.pop_front();
        return dq.size();
    }
};

int main()
{
    RecentCounter rc;
    cout << rc.ping(1) << endl;    // 1
    cout << rc.ping(100) << endl;  // 2
    cout << rc.ping(3001) << endl; // 3
    cout << rc.ping(3002) << endl; // 3
    return 0;
}
