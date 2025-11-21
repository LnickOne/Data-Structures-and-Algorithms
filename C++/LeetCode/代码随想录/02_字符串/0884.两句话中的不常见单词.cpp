/*
句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。
如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现，那么这个单词就是 不常见的 。
给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按任意顺序 组织。

示例 1：
输入：s1 = "this apple is sweet", s2 = "this apple is sour"
输出：["sweet","sour"]

示例 2：
输入：s1 = "apple apple", s2 = "banana"
输出：["banana"]
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  vector<string> uncommonFromSentences(string s1, string s2)
  {
    vector<string> result;
    unordered_map<string, int> s1Map;
    unordered_map<string, int> s2Map;
    string str;
    for (int i = 0; i < s1.size(); i += 1)
    {
      if (s1[i] != ' ')
      {
        str += s1[i];
      }
      if (s1[i] == ' ')
      {
        s1Map[str]++;
        str.clear();
      }
      else if (i == s1.size() - 1)
      {
        s1Map[str]++;
        str.clear();
      }
    }
    for (int i = 0; i < s2.size(); i += 1)
    {
      if (s2[i] != ' ')
      {
        str += s2[i];
      }
      if (s2[i] == ' ')
      {
        s2Map[str]++;
        str.clear();
      }
      else if (i == s2.size() - 1)
      {
        s2Map[str]++;
        str.clear();
      }
    }
    for (const auto &pair : s1Map)
    {
      if (s2Map.find(pair.first) == s2Map.end() && pair.second == 1)
        result.push_back(pair.first);
    }
    for (const auto &pair : s2Map)
    {
      if (s1Map.find(pair.first) == s1Map.end() && pair.second == 1)
        result.push_back(pair.first);
    }
    return result;
  }
};
int main()
{
  string s1 = "this apple is sweet";
  string s2 = "this apple is sour";
  Solution solution;
  vector<string> result = solution.uncommonFromSentences(s1, s2);
  for (auto &pair : result)
  {
    cout << pair << " ";
  }
  cout << endl;
  s1 = "apple apple";
  s2 = "banana";
  result = solution.uncommonFromSentences(s1, s2);
  for (auto &pair : result)
  {
    cout << pair << " ";
  }
  cout << endl;
  return 0;
}