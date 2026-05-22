/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/RQku0D)
题目描述
给定一个非空字符串 s, 判断最多从字符串中删除一个字符能否得到回文字符串。
题目样例
示例1
- 输入: s = "aba"
- 输出: true
示例2
- 输入: s = "abca"
- 输出: true
示例3
- 输入: s = "abc"
- 输出: false
题目思考
1. 如何利用只删除 1 个字符这个条件?
解决方案
方案1
思路
- 递归 + canDelete 标记: 遇到不等字符时若还有删除机会, 则左指针右移或右指针左移 (各尝试一次), 置 flag 为 false 继续
- 代码简洁, 但递归栈有 O(N) 空间消耗
复杂度
- 时间复杂度 O(N): 遇到不等字符时额外判断两次, 总计 O(2N)
- 空间复杂度 O(N): 递归栈的消耗
方案2
思路
- 迭代版本: 提取『判断子串是否回文』的辅助函数
- 头尾双指针向中间靠拢, 遇到不等字符时分别跳过左字符或右字符, 对两个子串调用辅助函数, 有一个是回文则返回 true
- 空间 O(1)
复杂度
- 时间复杂度 O(N): 遇到不等字符时额外判断两次, 总计 O(2N)
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
    bool isPalin(const string &s, int b, int e)
    {
        while (b < e)
        {
            if (s[b] != s[e]) return false;
            b++; e--;
        }
        return true;
    }
public:
    // 方案2: 迭代
    bool validPalindrome(string s)
    {
        int b = 0, e = s.size() - 1;
        while (b < e)
        {
            if (s[b] == s[e]) { b++; e--; }
            else return isPalin(s, b + 1, e) || isPalin(s, b, e - 1);
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << boolalpha;
    cout << s.validPalindrome("aba") << endl;  // true
    cout << s.validPalindrome("abca") << endl; // true
    cout << s.validPalindrome("abc") << endl;  // false
    cout << s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsmydgjpfdhooxfuupuculmgmqfvnbgtapekouга") << endl; // false
    return 0;
}
