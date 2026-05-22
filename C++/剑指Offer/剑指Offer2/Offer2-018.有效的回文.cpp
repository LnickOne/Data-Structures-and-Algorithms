/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/XltzEq)
题目描述
给定一个字符串 s, 验证 s 是否是回文串, 只考虑字母和数字字符, 忽略字母大小写。
本题中将空字符串定义为有效的回文串。
题目样例
示例1
- 输入: s = "A man, a plan, a canal: Panama"
- 输出: true
- 解释: "amanaplanacanalpanama" 是回文串
示例2
- 输入: s = "race a car"
- 输出: false
题目思考
1. 如何做到只考虑字母和数字, 且忽略大小写?
解决方案
思路
- 经典头尾双指针判断回文, 向中间靠拢依次比较字符
- 在比较前用 while 循环跳过连续的非字母数字字符 (isalnum)
- 比较时统一转为小写 (tolower) 以忽略大小写
复杂度
- 时间复杂度 O(N): 只需遍历每个字符一遍
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++; j--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << boolalpha;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl; // true
    cout << s.isPalindrome("race a car") << endl;                     // false
    cout << s.isPalindrome("") << endl;                               // true
    cout << s.isPalindrome("0P") << endl;                             // false
    return 0;
}
