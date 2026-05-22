/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/MPnaiL)
题目描述
给定两个字符串 s1 和 s2, 判断 s2 是否包含 s1 的某个变位词 (排列)。
题目样例
示例1
- 输入: s1 = "ab", s2 = "eidbaooo"
- 输出: true
- 解释: s2 包含 s1 的排列之一 "ba"
示例2
- 输入: s1 = "ab", s2 = "eidboaoo"
- 输出: false
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 暴力两重循环 O(MN), 可能超时
- 固定窗口大小为 s1 长度的滑动窗口:
  - 维护 s1 和 s2 窗口的字符计数数组 cnt1/cnt2 (26个字母)
  - 维护未匹配字符数 unmatch (初始为 s1 长度)
  - 右边界右移时: cnt2[rc]++, 若 cnt2[rc] <= cnt1[rc] 则找到一个匹配 unmatch--; 否则 unmatch++
  - 窗口超长需移除左边界: cnt2[lc]--, 若 cnt2[lc] >= cnt1[lc] 则移除了多余字符 unmatch--; 否则 unmatch++
  - unmatch==0 时找到一个有效变位词
复杂度
- 时间复杂度 O(N): 只需遍历 s2 一遍 (N 是 s2 的长度)
- 空间复杂度 O(1): 计数数组大小固定为 26
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size()) return false;
        int cnt1[26] = {}, cnt2[26] = {};
        for (char c : s1) cnt1[c - 'a']++;
        int unmatch = s1.size();
        int le1 = s1.size(), le2 = s2.size();
        for (int r = 0; r < le2; r++)
        {
            int rc = s2[r] - 'a';
            cnt2[rc]++;
            if (cnt2[rc] <= cnt1[rc]) unmatch--;
            else unmatch++;
            if (r >= le1)
            {
                int lc = s2[r - le1] - 'a';
                cnt2[lc]--;
                if (cnt2[lc] >= cnt1[lc]) unmatch--;
                else unmatch++;
            }
            if (unmatch == 0) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << boolalpha;
    cout << s.checkInclusion("ab", "eidbaooo") << endl; // true
    cout << s.checkInclusion("ab", "eidboaoo") << endl; // false
    cout << s.checkInclusion("adc", "dcda") << endl;    // true
    return 0;
}
