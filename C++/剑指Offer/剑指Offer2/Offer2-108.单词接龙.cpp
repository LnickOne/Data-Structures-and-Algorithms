/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/om3reC/)
题目描述
给定 beginWord、endWord 和字典 wordList, 找从 beginWord 到 endWord 的最短转换序列的单词数目。每次只能改变一个字母, 中间单词必须在字典中。不存在则返回 0。
题目样例
示例1
- 输入: beginWord="hit", endWord="cog", wordList=["hot","dot","dog","lot","log","cog"]
- 输出: 5 (hit->hot->dot->dog->cog)
示例2
- 输入: beginWord="hit", endWord="cog", wordList=["hot","dot","dog","lot","log"]
- 输出: 0
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- BFS 按层扩展: 每次替换单词的每一位为 a-z, 若新词在字典中则加入队列并从字典移除
- 初始 cnt=1 (beginWord), 找到 endWord 时返回 cnt
复杂度
- 时间复杂度 O(C^2*25*N): C 为单词长度, N 为字典大小
- 空间复杂度 O(C*N): 队列和字典集合
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        wordSet.erase(beginWord);
        int cnt = 1;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                string cur = q.front(); q.pop();
                if (cur == endWord) return cnt;
                for (int j = 0; j < (int)cur.size(); ++j)
                {
                    char orig = cur[j];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c == orig) continue;
                        cur[j] = c;
                        if (wordSet.count(cur))
                        {
                            wordSet.erase(cur);
                            q.push(cur);
                        }
                        cur[j] = orig;
                    }
                }
            }
            ++cnt;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<string> w1 = {"hot","dot","dog","lot","log","cog"};
    cout << sol.ladderLength("hit", "cog", w1) << endl; // 5
    vector<string> w2 = {"hot","dot","dog","lot","log"};
    cout << sol.ladderLength("hit", "cog", w2) << endl; // 0
    return 0;
}
