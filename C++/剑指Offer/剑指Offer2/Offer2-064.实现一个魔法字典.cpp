/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/US1pGT/)
题目描述
实现 MagicDictionary 类:
- buildDict(string[] dictionary): 用互不相同的字符串数组初始化
- search(string searchWord): 判断能否只改变 searchWord 中一个字母使其与字典中某单词匹配
题目样例
示例1
- 输入: ["MagicDictionary","buildDict","search","search","search","search"]
         [[],[["hello","leetcode"]],["hello"],["hhllo"],["hell"],["leetcoded"]]
- 输出: [null,null,false,true,false,false]
题目思考
1. 需要使用什么数据结构?
解决方案
思路
- 直接将词典保存为 vector, search 时遍历每个单词
- 判断函数: 长度相同且恰好有 1 个字符不同
复杂度
- 时间复杂度 O(NC): 每次 search 遍历词典所有字符
- 空间复杂度 O(NC): 存储词典所有字符
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MagicDictionary
{
    vector<string> dict;
    bool match(const string &a, const string &b)
    {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < (int)a.size(); i++)
            if (a[i] != b[i] && ++diff > 1) return false;
        return diff == 1;
    }
public:
    void buildDict(vector<string> dictionary) { dict = dictionary; }
    bool search(string searchWord)
    {
        for (auto &w : dict) if (match(w, searchWord)) return true;
        return false;
    }
};

int main()
{
    cout << boolalpha;
    MagicDictionary md;
    md.buildDict({"hello", "leetcode"});
    cout << md.search("hello") << endl;     // false
    cout << md.search("hhllo") << endl;     // true
    cout << md.search("hell") << endl;      // false
    cout << md.search("leetcoded") << endl; // false
    return 0;
}
