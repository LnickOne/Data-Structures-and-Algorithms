#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
给你一个字符串 s，找到 s 中最长的回文子串
示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：
输入：s = "cbbd"
输出："bb"
 */
class Solution
{
public:
    /*
    动态规划五部曲
    1.确定DP数组的含义
    s[1]，s[2]，s[3] 这个子串是回文的，那么只需要比较 s[0]和s[4]这两个元素是否相同，如果相同的话，这个字符串s 就是回文串。
    那么此时我们是不是能找到一种递归关系，也就是判断一个子字符串（字符串下标范围[i,j]）是否回文，
    依赖于子字符串（下标范围[i + 1, j - 1]）） 是否是回文。
    所以为了明确这种递归关系，我们的dp数组是要定义成一位二维dp数组。
    dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是回文子串,dp[i][j]为true，否则为false。
    2.确定递推公式
    在确定递推公式时，就要分析如下几种情况。
    整体上是两种，就是s[i] 与s[j] 相等，s[i] 与s[j] 不相等这两种。
    当s[i] 与s[j] 不相等，dp[i][j] 一定是false。
    当s[i] 与s[j] 相等时，有如下三种情况
    情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
    情况二：下标i 与 j相差为1，例如aa，也是回文子串
    情况三：下标：i 与 j相差大于1的时候，例如cabac，此时s[i] 与s[j] c==c 已经相同了
    我们看i到j区间是不是回文子串就看aba是不是回文就可以了，那么aba的区间就是 i +1 与 j - 1区间，这个区间是不是回文就看dp [i + 1][j - 1] 是否为true。
    3.初始化DP数组
    dp[i][j]可以初始化为true么？ 当然不行，怎能刚开始就全都匹配上了。所以dp[i][j]初始化为false。
    4.确定遍历顺序
    情况三是根据dp[i + 1][j - 1]是否为true，在对dp[i][j]进行赋值true的。
    如果这矩阵是从上到下，从左到右遍历，那么会用到没有计算过的dp[i + 1][j - 1]，也就是根据不确定是不是回文的区间[i+1,j-1]，来判断了[i,j]是不是回文，那结果一定是不对的。
    所以一定要从下到上，从左到右遍历，这样保证dp[i + 1][j - 1]都是经过计算的。
    5.举例推导DP数组
     */
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        string result;
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for (int i = s.size(); i >= 0; i-=1)
        {
            for (int j = i; j < s.size(); j+=1)
            {
                if (s[i] == s[j])
                {
                    if (j - i == 0)
                        dp[i][j] = true;
                    if (j - i == 1)
                        dp[i][j] = true;
                    if (j - i > 1)
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (s[i] != s[j])
                    dp[i][j] = false;
                if (dp[i][j] == true)
                    if (j - i + 1 > result.size())
                        result = s.substr(i, j - i + 1);
            }
        }
        return result;
    }
};

int main()
{
    string s = "babad";
    string s1 = "bsadwqdsadlkkaklkkdwiqobad";
    string s2 = "cbc";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    cout << sol.longestPalindrome(s1) << endl;
    cout << sol.longestPalindrome(s2) << endl;
    return 0;
}