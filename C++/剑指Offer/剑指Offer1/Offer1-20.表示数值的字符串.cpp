/* > 题目难度: 中等
> [原题链接](https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/)
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"、"-1E-16"及"12e+5.4"都不是。
题目样例
示例
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
题目思考
1. 如何高效地处理各类情况?
2. 边界情况分为几类?
解决方案
思路分析
- 首先确定字符串中允许有哪些字符, 以及各自需要满足什么条件 (如果面试遇到这种问题, 在模糊的地方一定要多沟通细节, 比如前导 0, 小数点位置等):
  - 数字
    - 数量没有上限, 但至少需要有 1 个
    - 无需处理前导 0 (因为题目用例里 0123 是有效的)
  - `e`
    - 只能有 1 个
    - 不能是大写 E
    - **左右都必须有至少一个数字**
  - `+/-`
    - `e` 的两边可以每边最多出现 1 个
    - 都必须在开头
  - `.`
    - 只能有 1 个
    - 只能出现在 `e` 之前
    - 可以出现在开头符号之后或数字之间
  - 空格
    - 只能出现在开头和末尾
- 根据上面分析, 一个自然的思路就是按照 `e` 将数字分为左右两部分, 其中右边唯一要求是不能有小数点, 别的和左边一样
- 这样我们就可以将分析数字的部分提取成一个方法, 额外传入一个 flag 表示是否可以有小数点, 然后分左右两部分判断即可~ 当然如果没有 `e` 的话那直接判断一次就行
实现
- 下面代码完全基于上述分析实现, 必要步骤都有详细注释
复杂度
- 时间复杂度 `O(N)`
  - 只需要对每个字符判断一次
- 空间复杂度 `O(1)`
  - 只使用了常数个变量
*/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        // 去除首尾空格
        int left = 0, right = (int)s.size() - 1;
        while (left <= right && s[left] == ' ')
            left++;
        while (right >= left && s[right] == ' ')
            right--;
        if (left > right)
            return false;
        s = s.substr(left, right - left + 1);

        // isValid: 判断子串是否是合法数字, allowDot 表示是否允许小数点
        auto isValid = [](const string &t, bool allowDot) -> bool
        {
            bool hasNum = false;
            bool hasDot = false;
            for (int i = 0; i < (int)t.size(); i++)
            {
                char c = t[i];
                if (c == '+' || c == '-')
                {
                    // 符号只能出现在开头
                    if (i != 0)
                        return false;
                }
                else if (c == '.')
                {
                    if (!allowDot)
                        return false;
                    if (hasDot)
                        return false;
                    hasDot = true;
                }
                else if (c >= '0' && c <= '9')
                {
                    hasNum = true;
                }
                else
                {
                    // 其他字符均非法
                    return false;
                }
            }
            return hasNum;
        };

        // 查找 'e' 的位置
        size_t ePos = s.find('e');
        if (ePos == string::npos)
        {
            // 没有 e, 直接判断整体, 允许小数点
            return isValid(s, true);
        }
        else
        {
            // 按 e 分左右, 左边可以有小数点, 右边不行
            string leftPart = s.substr(0, ePos);
            string rightPart = s.substr(ePos + 1);
            return isValid(leftPart, true) && isValid(rightPart, false);
        }
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.isNumber("0") << endl;         // true
    cout << sol.isNumber(" 0.1 ") << endl;     // true
    cout << sol.isNumber("abc") << endl;       // false
    cout << sol.isNumber("1 a") << endl;       // false
    cout << sol.isNumber("2e10") << endl;      // true
    cout << sol.isNumber(" -90e3   ") << endl; // true
    cout << sol.isNumber(" 1e") << endl;       // false
    cout << sol.isNumber("e3") << endl;        // false
    cout << sol.isNumber(" 6e-1") << endl;     // true
    cout << sol.isNumber(" 99e2.5 ") << endl;  // false
    cout << sol.isNumber("53.5e93") << endl;   // true
    cout << sol.isNumber(" --6 ") << endl;     // false
    cout << sol.isNumber("-+3") << endl;       // false
    cout << sol.isNumber("95a54e53") << endl;  // false
    return 0;
}
