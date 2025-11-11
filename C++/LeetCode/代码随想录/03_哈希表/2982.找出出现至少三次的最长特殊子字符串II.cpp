/*
给你一个仅由小写英文字母组成的字符串 s 。
如果一个字符串仅由单一字符组成，那么它被称为 特殊 字符串。
例如，字符串 "abc" 不是特殊字符串，而字符串 "ddd"、"zz" 和 "f" 是特殊字符串。
返回在 s 中出现 至少三次 的 最长特殊子字符串 的长度，如果不存在出现至少三次的特殊子字符串，则返回 -1 。
子字符串 是字符串中的一个连续 非空 字符序列。
示例 1：
输入：s = "aaaa"
输出：2
解释：出现三次的最长特殊子字符串是 "aa" ：子字符串 "aaaa"、"aaaa" 和 "aaaa"。
可以证明最大长度是 2 。
示例 2：
输入：s = "abcdef"
输出：-1
解释：不存在出现至少三次的特殊子字符串。因此返回 -1 。
示例 3：
输入：s = "abcaba"
输出：1
解释：出现三次的最长特殊子字符串是 "a" ：子字符串 "abcaba"、"abcaba" 和 "abcaba"。
可以证明最大长度是 1 。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int maximumLength(string s)
    {
        // 将字符串分解为连续相同字符的组
        vector<pair<char, int>> groups;
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            char c = s[i];
            int cnt = 0;
            while (i < n && s[i] == c)
            {
                cnt++;
                i++;
            }
            groups.emplace_back(c, cnt);
        }

        // 按字符分组存储连续长度
        unordered_map<char, vector<int>> char_groups;
        for (auto &p : groups)
        {
            char_groups[p.first].push_back(p.second);
        }

        int max_result = -1;
        // 检查每个字符的所有可能长度
        for (auto &entry : char_groups)
        {
            auto &lengths = entry.second;
            int max_len = *max_element(lengths.begin(), lengths.end());
            int current_max = 0;

            // 从最大可能长度开始检查
            for (int k = max_len; k >= 1; k--)
            {
                int total = 0;
                for (int l : lengths)
                {
                    if (l >= k)
                    {
                        total += (l - k + 1);
                        if (total >= 3)
                            break; // 提前退出以优化
                    }
                }
                if (total >= 3)
                {
                    current_max = k;
                    break; // 找到当前字符的最大可能长度
                }
            }
            if (current_max > max_result)
            {
                max_result = current_max;
            }
        }
        return max_result > 0 ? max_result : -1;
    }
};
int main()
{
    Solution s;
    string str = "aaaa";
    string str1 = "abcdef";
    string str2 = "abcaba";
    cout << s.maximumLength(str) << endl;
    cout << s.maximumLength(str1) << endl;
    cout << s.maximumLength(str2) << endl;
    return 0;
}