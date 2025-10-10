#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
给你一个字符串 s 。
我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
返回一个表示每个字符串片段的长度的列表。
示例 1：
输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
示例 2：
输入：s = "eccbbbbdec"
输出：[10]
s 仅由小写英文字母组成
*/
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        if (s.empty())
            return {};
        vector<int> result;
        vector<int> last_index(26, 0); // 字母出现最后最远的下标
        for (int i = 0; i < s.size(); i++)
        {
            last_index[s[i] - 'a'] = i;
        }
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, last_index[s[i] - 'a']);
            if (i == right)
            {
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return result;
    }
};
int main()
{

    return 0;
}