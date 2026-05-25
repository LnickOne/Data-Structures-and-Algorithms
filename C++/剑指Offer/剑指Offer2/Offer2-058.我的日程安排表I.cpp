/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/fi9suh/)
题目描述
实现 MyCalendar 类来存放日程安排 [start, end) (半开区间)。
book(start, end): 若新日程与已有日程无重叠则添加并返回 true, 否则返回 false。
题目样例
示例1
- 输入: ["MyCalendar","book","book","book"] [[],[10,20],[15,25],[20,30]]
- 输出: [null,true,false,true]
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 用 map<int,int> 存储区间 (start->end), map 按 start 自动排序
- book 时用 lower_bound 找到第一个 start >= 新区间 start 的区间
- 只需检查其前一个区间和当前区间是否与新区间重叠
- 两区间 [s1,e1) 和 [s2,e2) 重叠的条件: s1<e2 且 s2<e1
复杂度
- 时间复杂度 O(NlogN): 每次 book 的 lower_bound 为 O(logN)
- 空间复杂度 O(N): map 存储所有区间
 */
#include <iostream>
#include <map>
using namespace std;

class MyCalendar
{
    map<int, int> mp;
public:
    bool book(int start, int end)
    {
        auto it = mp.lower_bound(start);
        if (it != mp.end() && it->first < end) return false;
        if (it != mp.begin())
        {
            --it;
            if (it->second > start) return false;
        }
        mp[start] = end;
        return true;
    }
};

int main()
{
    MyCalendar cal;
    cout << boolalpha;
    cout << cal.book(10, 20) << endl; // true
    cout << cal.book(15, 25) << endl; // false
    cout << cal.book(20, 30) << endl; // true
    return 0;
}
