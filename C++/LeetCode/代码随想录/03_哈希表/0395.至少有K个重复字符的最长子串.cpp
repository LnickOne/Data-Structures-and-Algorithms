#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        return dfs(s, 0, s.size(), k);
    }

    int dfs(const string &s, int start, int end, int k)
    {
        if (end - start < k)
            return 0; // 子串长度小于k，不可能满足条件
        // 统计字符频率
        unordered_map<char, int> map;
        for (int i = start; i < end; ++i)
        {
            ++map[s[i]];
        }

        // 检查是否所有字符都满足条件
        bool allValid = true;
        for (int i = 0; i < 26; ++i)
        {
            if (map['a' + i] > 0 && map['a' + i] < k)
            {
                allValid = false;
                break;
            }
        }

        // 如果所有字符都满足条件，返回当前子串长度
        if (allValid)
            return end - start;

        // 否则在不满足条件的字符处分割，递归处理
        int result = 0;
        int i = start;
        for (int j = start; j < end; ++j)
        {
            if (map[s[j]] < k)
            { // 遇到不满足条件的字符
                if (j - i >= k)
                { // 如果分割的子串可能满足条件
                    result = max(result, dfs(s, i, j, k));
                }
                i = j + 1; // 从下一个位置开始新的子串
            }
        }
        // 处理最后一段
        if (end - i >= k)
        {
            result = max(result, dfs(s, i, end, k));
        }
        return result;
    }
};

int main()
{
    Solution s;
    string s1 = "aaabb";
    int k = 3;
    int result = s.longestSubstring(s1, k);
    cout << result << endl;

    // 更多测试用例
    cout << s.longestSubstring("ababbc", 2) << endl;  // 应该输出5，"ababb"是最长的满足条件的子串
    cout << s.longestSubstring("weitong", 2) << endl; // 应该输出0，没有满足条件的子串
    return 0;
}