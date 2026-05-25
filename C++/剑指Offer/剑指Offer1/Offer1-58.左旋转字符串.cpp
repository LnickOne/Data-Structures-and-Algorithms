/* > 题目难度: 简单

> [原题链接](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

题目描述

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字 2，该函数将返回左旋转两位得到的结果"cdefgab"。

- 1 <= k < s.length <= 10000

题目样例

示例

- 输入: s = "abcdefg", k = 2
- 输出: "cdefgab"

- 输入: s = "lrloseumgh", k = 6
- 输出: "umghlrlose"

题目思考

1. 如果要求不能使用语言内置函数, 该如何做?

解决方案

方案 1

思路

- 根据题目描述, 直接利用 substr 切片, 一行代码即可搞定
- 将下标 n 之后的部分与下标 0 到 n-1 的部分拼接即可

复杂度

- 时间复杂度 O(N): 切片的时间复杂度
- 空间复杂度 O(N): 返回新字符串

方案 2

思路

- 如果要求不能使用语言内置函数, 又该怎么做呢?
- 很显然我们可以从下标为 k 的地方开始遍历, 将后面的字符依次加入结果中
- 遍历到末尾后, 再从 0 开始遍历到 k, 将这部分字符再加入结果中即可
- 这种方案跟语言无关, 比较通用

复杂度

- 时间复杂度 O(N): 每个字符只遍历一次
- 空间复杂度 O(N): 存储结果字符串
*/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        // 方法 1: substr 切片
        return s.substr(n) + s.substr(0, n);
    }
};

int main()
{
    Solution s;

    // 示例 1: s = "abcdefg", k = 2, 期望输出 "cdefgab"
    cout << s.reverseLeftWords("abcdefg", 2) << endl; // cdefgab

    // 示例 2: s = "lrloseumgh", k = 6, 期望输出 "umghlrlose"
    cout << s.reverseLeftWords("lrloseumgh", 6) << endl; // umghlrlose

    // k = 1
    cout << s.reverseLeftWords("abcd", 1) << endl; // bcda

    // k = length - 1
    cout << s.reverseLeftWords("abcd", 3) << endl; // dabc

    return 0;
}
