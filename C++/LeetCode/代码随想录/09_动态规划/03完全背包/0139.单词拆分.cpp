#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。
示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/
class Solution
{
public:
    /*
      动态规划五部曲
      1. 确定dp数组以及下标的含义
      dp[j]：表示长度为j的字符串是否可以由wordDict中的单词拼接而成
      2. 确定递推关系
      dp[j]是true还是false
      依赖于前面的一段子串正好是字典里的单词，并且dp[j-weight[i]]也是true,dp[j]才是true
      也就是说dp[j-weight[i]]已经是true了，并且当前的字符串长度减去单词长度的子串正好是字典里的单词，
      这样就可以推出dp[j]也是true
      3. 确定初始值
      dp[0] = true
      4. 确定遍历顺序
      转换为完全背包中的求排列问题，因为12,21是不同的，所以是先遍历背包再遍历物品
      5. 举例推导dp数组
      */
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int backpack_capacity = s.size();
        vector<int> weight;
        for (string &word : wordDict)
            weight.push_back(word.size());
        vector<bool> dp(backpack_capacity + 1, false);
        dp[0] = true;                                // 下标0初始化为true,其他初始化为false
        for (int j = 0; j <= backpack_capacity; j++) // 遍历背包
        {
            for (int i = 0; i < weight.size(); i++) // 遍历物品
            {
                if (j >= weight[i] && dp[j - weight[i]] && s.substr(j - weight[i], weight[i]) == wordDict[i])
                    dp[j] = true;
            }
        }
        return dp[backpack_capacity];
    }
};
int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution solve;
    bool ans = solve.wordBreak(s, wordDict);
    cout << ans << endl;
    return 0;
}