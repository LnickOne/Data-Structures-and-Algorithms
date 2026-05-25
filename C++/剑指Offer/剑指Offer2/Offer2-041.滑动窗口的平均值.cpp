/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/qIsx9U/)
题目描述
给定整数数据流和窗口大小 size, 实现 MovingAverage 类:
- MovingAverage(int size): 初始化对象
- double next(int val): 每次调用往滑动窗口增加一个整数, 返回最后 size 个值的移动平均值
题目样例
示例1
- 输入: ["MovingAverage","next","next","next","next"] [[3],[1],[10],[3],[5]]
- 输出: [null,1.0,5.5,4.66667,6.0]
题目思考
1. 可以使用什么数据结构模拟整个过程?
2. 如何优化时间复杂度?
解决方案
思路
- 用 deque 维护最近 size 个元素, 同时维护当前窗口总和
- 每次加入新元素时, 若超过 size 则弹出队头并从总和减去
- 返回总和除以当前元素个数
复杂度
- 时间复杂度 O(1): next 函数只需要常数次操作
- 空间复杂度 O(size): 需要额外双端队列存储 size 个元素
 */
#include <iostream>
#include <deque>
using namespace std;

class MovingAverage
{
    int sz;
    deque<int> dq;
    long long sm = 0;
public:
    MovingAverage(int size) : sz(size) {}
    double next(int val)
    {
        dq.push_back(val);
        sm += val;
        if ((int)dq.size() > sz)
        {
            sm -= dq.front();
            dq.pop_front();
        }
        return (double)sm / dq.size();
    }
};

int main()
{
    MovingAverage ma(3);
    cout << ma.next(1) << endl;  // 1.0
    cout << ma.next(10) << endl; // 5.5
    cout << ma.next(3) << endl;  // 4.66667
    cout << ma.next(5) << endl;  // 6.0
    return 0;
}
