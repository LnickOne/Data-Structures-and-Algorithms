/*
给你一个字符串 date ，它的格式为 Day Month Year ，其中：
Day 是集合 {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"} 中的一个元素。
Month 是集合 {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
"Oct", "Nov", "Dec"} 中的一个元素。 Year 的范围在 ​[1900, 2100]
之间。 请你将字符串转变为 YYYY-MM-DD 的格式，其中： YYYY 表示 4 位的年份。 MM
表示 2 位的月份。 DD 表示 2 位的天数。

示例 1：
输入：date = "20th Oct 2052"
输出："2052-10-20"
示例 2：
输入：date = "6th Jun 1933"
输出："1933-06-06"
示例 3：
输入：date = "26th May 1960"
输出："1960-05-26"
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string reformatDate(string date)
    {
        // 提取年份
        string year = date.substr(date.length() - 4);
        // 提取月份
        int monthStart = date.length() - 8;
        string monthStr = date.substr(monthStart, 3);
        unordered_map<string, int> mon_map = {
            {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
        string month = to_string(mon_map[monthStr]);
        if (month.size() == 1)
            month = "0" + month;
        // 提取日期
        int i = 0;
        while (isdigit(date[i]))
            i += 1;
        string day = date.substr(0, i);
        if (day.size() == 1)
            day = "0" + day;
        return year + "-" + month + "-" + day;
    }
};
int main()
{
    string date = "20th Oct 2052";
    Solution s;
    cout << s.reformatDate(date) << endl;
    date = "6th Jun 1933";
    cout << s.reformatDate(date) << endl;
    date = "26th May 1960";
    cout << s.reformatDate(date) << endl;
    return 0;
}