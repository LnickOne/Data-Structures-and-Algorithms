/*
给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
文本的最后一行应为左对齐，且单词之间不插入额外的空格。
注意:
单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例 1:

输入: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{
public:
    vector<string> fullJustify(const vector<string> &words, int maxWidth)
    {
        int i = 0, j = 0, m = 0;
        int n = words.size(), temp_width = 0, temp_space = 0, num_space = 0;
        vector<string> temp_words, result;
        string temp_str = "";
        while (i < n)
        {
            temp_words.clear();
            temp_width = maxWidth - words[i].length();
            temp_words.push_back(words[i]);
            temp_str = "";
            while (i + 1 < n && temp_width >= 1 + words[i + 1].length())
            {
                ++i;
                temp_width -= (words[i].length() + 1);
                temp_words.push_back(words[i]);
            }
            ++i;
            m = temp_words.size();
            num_space = m - 1;
            temp_space = maxWidth;
            for (j = 0; j < m; ++j)
            {
                temp_space -= temp_words[j].length();
            }
            for (j = 0; j < m - 1; ++j)
            {
                temp_str += temp_words[j];
                temp_str += string((i == n ? 1 : ceil(double(temp_space) / num_space)), ' ');
                temp_space -= (i == n ? 1 : ceil(double(temp_space) / num_space));
                --num_space;
            }
            temp_str += temp_words[j];
            temp_str += string(temp_space, ' ');
            result.push_back(temp_str);
        }

        return result;
    }
}

;

int main()
{
    vector<string> words = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth = 20;
    Solution s;
    vector<string> result = s.fullJustify(words, maxWidth);
    for (auto &str : result)
    {
        cout << str << endl;
    }
    return 0;
}