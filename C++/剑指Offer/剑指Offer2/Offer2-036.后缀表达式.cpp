/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/8Zf90G/)
题目描述
根据逆波兰表示法, 求该后缀表达式的计算结果。
有效算符包括 +、-、*、/。整数除法只保留整数部分。
题目样例
示例1
- 输入: tokens = ["2","1","+","3","*"]
- 输出: 9
- 解释: ((2+1)*3) = 9
示例2
- 输入: tokens = ["4","13","5","/","+"]
- 输出: 6
- 解释: (4+(13/5)) = 6
示例3
- 输入: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
- 输出: 22
题目思考
1. 如何模拟整个计算过程?
解决方案
思路
- 维护一个数字栈: 遇到数字则转 int 后入栈
- 遇到运算符则弹出栈顶两个数 (先弹的是 b, 后弹的是 a), 计算 a op b 后将结果压栈
- 注意除法使用截断到零的整数除法 (C++ 默认)
复杂度
- 时间复杂度 O(N): 遍历所有 token 一遍
- 空间复杂度 O(N): 栈最多存 N 个元素
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        for (auto &tok : tokens)
        {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/")
            {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (tok == "+") st.push(a + b);
                else if (tok == "-") st.push(a - b);
                else if (tok == "*") st.push(a * b);
                else st.push(a / b);
            }
            else
            {
                st.push(stoll(tok));
            }
        }
        return (int)st.top();
    }
};

int main()
{
    Solution sol;
    vector<string> t1 = {"2", "1", "+", "3", "*"};
    cout << sol.evalRPN(t1) << endl; // 9
    vector<string> t2 = {"4", "13", "5", "/", "+"};
    cout << sol.evalRPN(t2) << endl; // 6
    vector<string> t3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << sol.evalRPN(t3) << endl; // 22
    return 0;
}
