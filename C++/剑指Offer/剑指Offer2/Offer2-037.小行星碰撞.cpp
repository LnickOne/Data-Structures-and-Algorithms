/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/XagZNi/)
题目描述
给定整数数组 asteroids, 其中绝对值表示小行星大小, 正负表示移动方向 (正向右, 负向左)。
两个行星相互碰撞时较小的爆炸; 大小相同则两个都爆炸; 同向永远不碰。
找出碰撞后剩下的所有小行星。
题目样例
示例1
- 输入: asteroids = [5,10,-5]
- 输出: [5,10]
示例2
- 输入: asteroids = [8,-8]
- 输出: []
示例3
- 输入: asteroids = [10,2,-5]
- 输出: [10]
示例4
- 输入: asteroids = [-2,-1,1,2]
- 输出: [-2,-1,1,2]
题目思考
1. 可以使用什么数据结构模拟整个过程?
解决方案
思路
- 用栈模拟: 向右行星直接入栈
- 向左行星与栈顶 (向右行星) 比较: 栈顶更大则当前爆炸; 相等则两者都爆炸; 栈顶更小则栈顶爆炸继续循环
- 用 while 循环处理级联碰撞, 用 alive 标记当前行星是否幸存
复杂度
- 时间复杂度 O(N): 遍历整个数组一遍
- 空间复杂度 O(N): 栈最多存 N 个元素
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        for (int x : asteroids)
        {
            bool alive = true;
            while (alive && x < 0 && !st.empty() && st.top() > 0)
            {
                if (st.top() > -x) { alive = false; }
                else if (st.top() == -x) { st.pop(); alive = false; }
                else { st.pop(); }
            }
            if (alive) st.push(x);
        }
        vector<int> res;
        while (!st.empty()) { res.push_back(st.top()); st.pop(); }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    auto print = [](vector<int> &v) { for (int x : v) cout << x << " "; cout << endl; };
    vector<int> a1 = {5, 10, -5};
    auto r1 = sol.asteroidCollision(a1);
    print(r1); // 5 10
    vector<int> a2 = {8, -8};
    auto r2 = sol.asteroidCollision(a2);
    print(r2); // (空)
    vector<int> a3 = {10, 2, -5};
    auto r3 = sol.asteroidCollision(a3);
    print(r3); // 10
    vector<int> a4 = {-2, -1, 1, 2};
    auto r4 = sol.asteroidCollision(a4);
    print(r4); // -2 -1 1 2
    return 0;
}
