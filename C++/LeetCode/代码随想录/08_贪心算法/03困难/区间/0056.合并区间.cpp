#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare); // 先排序再放入result中
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (result.back()[1] >= intervals[i][0])                       // 如果此时前一个区间的右边界大于等于后续区间的左边界则比较两个区间的右边界大小合并
                result.back()[1] = max(result.back()[1], intervals[i][1]); // 如需合并区间，则只需要更新右边界，因为排序后result.back()的左边界一定是最小值
            if (result.back()[1] < intervals[i][0])                        // 如果此时前一个区间的右边界小于后续区间的左边界则区间不重叠
                result.push_back(intervals[i]);                            // 区间不重叠就添加到result中
        }
        return result;
    }

    static bool compare(const vector<int> &a, const vector<int> &b) // 使用 const 引用，明确表示不会修改传入的 vector
    {
        return a[0] < b[0];
    }
};
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> intervals1 = {{10, 60}, {100, 160}, {150, 180}};
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    Solution s;
    vector<vector<int>> result = s.merge(intervals);
    vector<vector<int>> result1 = s.merge(intervals1);
    vector<vector<int>> result2 = s.merge(intervals2);
    for (auto &i : result1)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    for (auto &i : result2)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    for (auto &i : result)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}