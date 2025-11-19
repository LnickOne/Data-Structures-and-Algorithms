/*
给你一个字符串 s 和一个字符 letter ，
返回在 s 中等于 letter 字符所占的 百分比 ，向下取整到最接近的百分比。

示例 1：
输入：s = "foobar", letter = "o"
输出：33
解释：
等于字母 'o' 的字符在 s 中占到的百分比是 2 / 6 * 100% = 33% ，向下取整，所以返回 33 。

示例 2：
输入：s = "jjjj", letter = "k"
输出：0
解释：
等于字母 'k' 的字符在 s 中占到的百分比是 0% ，所以返回 0 。
*/
#include <iostream>
using namespace std;
class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int count = 0;
        for (char &c : s)
        {
            if (c == letter)
                count++;
        }
        return count * 100 / s.size();
    }
};
int main()
{
    string s = "foobar";
    char letter = 'o';
    Solution solution;
    int res = solution.percentageLetter(s, letter);
    cout << res << endl;
    return 0;
}