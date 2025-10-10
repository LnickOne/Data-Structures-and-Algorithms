#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
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
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    如果字符串的下标s[1]，s[2]，s[3] 这三个子串构成的子串是回文的，比如"aba"
    那么只需要比较 s[0]和s[4]这两个元素是否相同，如果相同的话，一整个字符串s 就是回文串。
    那么此时我们是不是能找到一种递归关系，
    判断一个子字符串（字符串下标范围[i,j]）是否回文，依赖于子字符串的下标范围[i + 1, j - 1] 是否是回文。
    为了明确这种递归关系，我们的dp数组是要定义成一位二维dp数组。
    dp[i][j]：表示一个区间范围[i,j]（注意是左闭右闭）字符串s在[i, j]范围内的子串是否是回文子串。
    2. 确定递推关系
    在确定递推公式时，就要分析如下几种情况。[i,.....,j]
    整体上是两种，就是s[i]与s[j]相等，s[i] 与s[j]不相等这两种。
    当s[i] 与s[j] 不相等，dp[i][j] 一定是false。
    当s[i] 与s[j] 相等时，有如下三种情况
    情况一：下标i与j相同，i==j，同一个字符例如a，当然是回文子串
    情况二：下标i与j相差为1，例如aa，也是回文子串
    情况三：下标：i与j相差大于1的时候，
    例如cabac，此时s[i] 与s[j] 已经字母相同了,我们看i到j区间的子串是不是回文子串就看aba是不是回文就可以了，
    那么aba的区间就是 i +1 与 j - 1区间，这个区间是不是回文就看dp [i + 1][j - 1] 是否为true。
    3. 确定初始值
    dp[i][j]可以初始化为true么？ 当然不行，怎能刚开始就全都匹配上了。所以dp[i][j]初始化为false。
    4. 确定遍历顺序
        字符串是由短变长的，所以从左到右遍历，从下到上遍历。
    情况三是根据dp[i + 1][j - 1]是否为true，在对dp[i][j]进行赋值true的。
    如果这矩阵是从上到下，从左到右遍历，那么会用到没有计算过的dp[i + 1][j - 1]，
    也就是根据不确定是不是回文的区间[i+1,j-1]，来判断了[i,j]是不是回文，那结果一定是不对的。
    所以一定要从左到右遍历,从下到上，这样保证dp[i + 1][j - 1]都是经过计算的。
    5. 举例推导dp数组
    */
    int countSubstrings(string s)
    {
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        for (int i = s.size() - 1; i >= 0; i--) // 注意遍历顺序，想象字符串是从最后面由短变长，所以i--,j++
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i == 0) // 情况一,"a"
                    {
                        dp[i][j] = true;
                    }
                    if (j - i == 1) // 情况二,"aa"
                    {
                        dp[i][j] = true;
                    }
                    if (j - i > 1) // 情况三 "cabc" i+1是a j-1是b cabc不是回文子串 "caac" caac是回文子串
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    if (dp[i][j] == true)
                        result++;
                }
            }
        }
        return result;
    }
};

int main()
{
    string s_1 = "abc";
    string s_2 = "aaa";
    string s_3 = "cabac";
    string s_4 = "caac";
    Solution s;
    cout << s.countSubstrings(s_1) << endl;
    cout << s.countSubstrings(s_2) << endl;
    cout << s.countSubstrings(s_3) << endl;
    cout << s.countSubstrings(s_4) << endl;
    return 0;
}