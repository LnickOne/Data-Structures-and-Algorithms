/*
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
示例 1：
输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：
输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
int main()
{
    string s_1 = "abc";
    string s_2 = "aaa";
    Solution s;
    cout << s.isPalindrome(s_1) << endl;
    cout << s.isPalindrome(s_2) << endl;
    return 0;
}
