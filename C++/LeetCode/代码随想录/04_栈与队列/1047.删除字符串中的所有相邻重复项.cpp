/*
给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 s 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
示例：
输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，
这是此时唯一可以执行删除操作的重复项。
之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
*/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> stack;
        for (char ch : s)
        {
            if (stack.empty())
            {
                stack.push(ch);
            }
            if (!stack.empty())
            {
                char top = stack.top();
                if (ch != top)
                    stack.push(ch);
                else if (ch == top)
                    stack.pop();
            }
        }
        string result;
        while (!stack.empty())
        {
            result += stack.top();
            stack.pop();
        }
        reverse(result.begin(), result.end());
        for (const char &ch : s)
        {
            if (result.empty() || result.back() != ch)
                result.push_back(ch);
            else
                result.pop_back();
        }
        return result;
    }
};

int main()
{
    Solution s;
    string s1 = "abbaca";
    string s2 = "abbbaca";
    string s3 = "abbbacaa";
    cout << s.removeDuplicates(s1) << endl;
    cout << s.removeDuplicates(s2) << endl;
    cout << s.removeDuplicates(s3) << endl;
    return 0;
}
