#include <iostream>
#include <vector>
#include <algorithm>
// #include <Windows.h>
using namespace std;
/*
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。
返回 需要移除区间的最小数量，使剩余区间互不重叠 。
示例 1:
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:
输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:
输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int result = 0;
        sort(intervals.begin(), intervals.end(), compare);
        // cout << "排序后" << endl;
        // for (auto &i : intervals)
        // {
        //     cout << i[0] << " " << i[1] << endl;
        // }
        // cout << endl;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[i - 1][1]) // 前一个的左边界小于后一个右边界的时候
            {
                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
                result++;
            }
        }
        // cout << "排序后" << endl;
        // for (auto &i : intervals)
        // {
        //     cout << i[0] << " " << i[1] << endl;
        // }
        return result;
    }
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
};

int main()
{
    // vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
    Solution s;
    s.eraseOverlapIntervals(intervals);
    cout << "最小移除区间数量为：" << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}