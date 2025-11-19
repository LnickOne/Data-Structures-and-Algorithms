/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。
示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
ransomNote 和 magazine 由小写英文字母组成
 */
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
            return false;
        unordered_map<char, int> map;
        for (char ch : magazine)
            map[ch]++;
        for (char ch : ransomNote)
            map[ch]--;
        for (const auto &iter : map)
            if (iter.second < 0)
                return false;
        // int map[26];
        // for (char ch : magazine)
        //     map[ch - 'a']++;
        // for (char ch : ransomNote)
        //     map[ch - 'a']--;
        // for (int val : map)
        //     if (val < 0)
        //         return false;
        return true;
    }
};

int main()
{
    string ransomNote_1 = "a", magazine_1 = "b";
    string ransomNote_2 = "aa", magazine_2 = "ab";
    string ransomNote_3 = "aa", magazine_3 = "aab";
    cout << Solution().canConstruct(ransomNote_3, magazine_3) << endl;
    return 0;
}