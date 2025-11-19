/*
给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
请你计算该表达式。返回一个表示表达式值的整数。
注意：
有效的算符为 "+"、'-'、'*' 和 '/' 。
每个操作数（运算对象）都可以是一个整数或者另一个表达式。
两个整数之间的除法总是 向零截断 。
表达式中不含除零运算。
输入是一个根据逆波兰表示法表示的算术表达式。
答案及所有中间计算结果可以用 32 位 整数表示。
示例 1：
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        long result;
        stack<long> stack;
        for (const string &str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                long nums1 = stack.top();
                stack.pop();
                long nums2 = stack.top();
                stack.pop();
                if (str == "+")
                    stack.push(nums2 + nums1);
                else if (str == "-")
                    stack.push(nums2 - nums1);
                else if (str == "*")
                    stack.push(nums2 * nums1);
                else if (str == "/")
                    stack.push(nums2 / nums1);
            }
            else
                stack.push(stol(str));
        }
        result = stack.top();
        stack.pop();
        return result;
    }
};

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    vector<string> tokens_1 = {"4", "13", "5", "/", "+"};
    Solution s;
    cout << s.evalRPN(tokens) << endl;
    cout << s.evalRPN(tokens_1) << endl;
    return 0;
}