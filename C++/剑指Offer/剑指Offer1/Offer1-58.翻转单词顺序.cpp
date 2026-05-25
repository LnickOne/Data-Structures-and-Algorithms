/* > 题目难度: 简单

> [原题链接](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/)

题目描述

输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

- 无空格字符构成一个单词。
- 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
- 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

题目样例

示例

- 输入: "the sky is blue"
- 输出: "blue is sky the"

- 输入: "  hello world!  "
- 输出: "world! hello"
- 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

题目思考

1. 如果要求不能使用语言内置函数, 该如何做?

解决方案

方案 1

思路

- 根据题目描述, 我们可以直接利用 stringstream 来分词, 再翻转, 最后用空格连接
- stringstream 会自动忽略连续的空白字符, 与 Python 不传参的 split 效果一致

复杂度

- 时间复杂度 O(N): 只遍历了一遍字符串
- 空间复杂度 O(N): 存储单词列表

方案 2

思路

- 如果要求不能使用语言内置函数, 又该怎么做呢?
- 这时候我们只能老老实实地从右向左遍历
- 此时需要使用一个变量记录当前的单词(即连续的非空字符)
- 然后遇到空格时, **如果当前单词不为空**时 (因为可能会遇到连续的空格), 将当前单词加入最终结果 res 中, 然后将当前单词重置为空
- 加入 res 时需要注意: 如果当前单词是第一个(res 为空的时候), 不加入空格, 否则先加空格再加这个单词, 保证不同单词以空格隔开
- **另外注意遍历结束后, 当前单词可能不为空, 也需要将其加入最终结果中**

复杂度

- 时间复杂度 O(N): 只遍历了一遍字符串
- 空间复杂度 O(N): 存储结果字符串
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // 方法 1: 使用 stringstream 分词, 翻转, 空格连接
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string res;
        for (int i = 0; i < (int)words.size(); i++)
        {
            if (i > 0)
                res += ' ';
            res += words[i];
        }
        return res;
    }
};

int main()
{
    Solution s;

    // 示例 1: "the sky is blue", 期望输出 "blue is sky the"
    cout << s.reverseWords("the sky is blue") << endl; // blue is sky the

    // 示例 2: "  hello world!  ", 期望输出 "world! hello"
    cout << s.reverseWords("  hello world!  ") << endl; // world! hello

    // 示例 3: "I am a student. ", 期望输出 "student. a am I"
    cout << s.reverseWords("I am a student. ") << endl; // student. a am I

    // 多余空格: "a good   example", 期望输出 "example good a"
    cout << s.reverseWords("a good   example") << endl; // example good a

    return 0;
}
