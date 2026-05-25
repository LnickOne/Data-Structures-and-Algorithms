/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/iIQa4I/)
题目描述
给定每日气温列表 temperatures, 对每个位置输出要等待几天才能观测到更高气温。
若之后气温都不会升高则输出 0。
题目样例
示例1
- 输入: temperatures = [73,74,75,71,69,72,76,73]
- 输出: [1,1,4,2,1,1,0,0]
示例2
- 输入: temperatures = [30,40,50,60]
- 输出: [1,1,1,0]
示例3
- 输入: temperatures = [30,60,90]
- 输出: [1,1,0]
题目思考
1. 可以使用什么数据结构模拟整个过程?
解决方案
思路
- 单调栈存下标, 保证从栈顶到栈底对应温度单调递增
- 逆序遍历: 先将栈顶小于等于当前温度的下标弹出 (它们对后续无意义)
- 若栈非空则栈顶即为后面最近更高温度的下标, 差值即为等待天数
- 将当前下标压栈
复杂度
- 时间复杂度 O(N): 每个元素最多入栈出栈各一次
- 空间复杂度 O(N): 栈最多存 N 个元素
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            if (!st.empty()) res[i] = st.top() - i;
            st.push(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    auto print = [](vector<int> &v) { for (int x : v) cout << x << " "; cout << endl; };
    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    auto r1 = sol.dailyTemperatures(t1);
    print(r1); // 1 1 4 2 1 1 0 0
    vector<int> t2 = {30, 40, 50, 60};
    auto r2 = sol.dailyTemperatures(t2);
    print(r2); // 1 1 1 0
    return 0;
}
