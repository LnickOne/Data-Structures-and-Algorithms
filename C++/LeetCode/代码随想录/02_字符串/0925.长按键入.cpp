/*
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
示例 1：
输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。
示例 2：
输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
*/
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        if (name.size() == typed.size() && name != typed)
            return false;
        if (name[name.size() - 1] != typed[typed.size() - 1])
            return false;
        int i = 0;
        int j = 0;
        while (i < name.size() && j < typed.size())
        {
            if (name[i] == typed[j]) // 相同则同时向后匹配
            {
                i += 1;
                j += 1;
            }
            if (name[i] != typed[j]) // 不相同
            {
                if (j == 0) // 如果是第一位就不相同直接返回false
                    return false;
                // j跨越重复项，向后移动，同时防止j越界
                while (j < typed.size() && typed[j] == typed[j - 1])
                    j += 1;
                if (name[i] == typed[j]) // j跨越重复项之后再次和name[i]匹配
                {
                    j += 1;
                    i += 1; // 相同则同时向后匹配
                }
                else
                    return false;
            }
        }
        // 说明name没有匹配完，例如 name:"pyplrzzzzdsfa" type:"ppyypllr"
        if (i < name.size())
            return false;
        // 说明type没有匹配完，例如 name:"alex" type:"alexxrrrrssda"
        while (j < typed.size())
        {
            if (typed[j] == typed[j - 1])
                j += 1;
            else
                return false;
        }
        return true;
    }
};

int main()
{
    Solution A = Solution();
    bool result1 = A.isLongPressedName("alex", "aaleex");
    bool result2 = A.isLongPressedName("saeed", "ssaaedd");
    bool result3 = A.isLongPressedName("saeed", "ssaaeedd");
    bool result4 = A.isLongPressedName("leelee", "lleeelee");
    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;
    cout << result4 << endl;
    return 0;
}