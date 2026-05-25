/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)
题目描述
路径字符串 path 以 "." 作为分隔符, 将 "." 替换为空格 " " 后返回加密字符串。
题目样例
示例1
- 输入: path="a.aef.qerf.bb"
- 输出: "a aef qerf bb"
题目思考
1. 如何优化效率?
解决方案
思路
- 遍历字符串, 遇到 '.' 替换为 ' ', 其余字符直接保留
复杂度
- 时间复杂度 O(N): 遍历一次
- 空间复杂度 O(N): 结果字符串
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string pathEncryption(string path)
    {
        for (char &c : path)
            if (c == '.')
                c = ' ';
        return path;
    }
};

int main()
{
    Solution sol;
    cout << sol.pathEncryption("a.aef.qerf.bb") << endl; // a aef qerf bb
    return 0;
}
