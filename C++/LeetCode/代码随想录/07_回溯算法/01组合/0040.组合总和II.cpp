#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
using namespace std;
/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
*/
class Solution
{
public:
    /*
    本题要求：
    1.candidates 中的每个数字在每个组合中只能使用一次。
    2.本题数组candidates的元素是有重复的。
    总结：要去重的是“同一树层上的使用过的元素”如果candidates[i] == candidates[i - 1] 并且 used[i - 1] == false，
    就说明：前一个树枝，使用了candidates[i - 1]，也就是说同一树层使用过candidates[i - 1]。
    used[i - 1] == false，说明同一树层candidates[i - 1]使用过
    额外知识:
    used[i - 1] == true，说明同一树枝candidates[i - 1]使用过,而 used[i - 1] == true，
    说明是进入下一层递归，去下一个数，所以是树枝上如果是树枝去重的题目那么就对这个进行操作
    */
    vector<vector<int>> combinationSum2(vector<int> &candidates, const int &target)
    {
        if (candidates.empty())
            return {};
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(candidates.size());
        sort(candidates.begin(), candidates.end());              // 本题关键是：树层去重，并对数组排序让其相同的元素都放在一起。
        backtracking(0, candidates, target, used, path, result); // 树层去重的话，需要对数组排序！排序是为了让相邻的元素放在一起好进行比较是否需要去重
        return result;
    }
    void backtracking(const int &start, const vector<int> &candidates, const int &target, vector<bool> &used, vector<int> &path, vector<vector<int>> &result)
    {
        if (accumulate(path.begin(), path.end(), 0) > target)
            return;
        if (accumulate(path.begin(), path.end(), 0) == target)
        {
            result.push_back(path);
            return;
        }
        unordered_set<int> set; // 用于对同一树层的元素进行去重，比如[1,1,2,5,6,7,10]，如果不加这个去重，那么就会出现[1,1,6],[1,2,5],[1,7]等重复的组合
        for (int i = start; i < candidates.size(); i++)
        {
            // used[i - 1] == false 才能表示，当前取的 candidates[i] 是从 candidates[i - 1] 回溯而来的。说明同一树层candidates[i - 1]使用过,
            // if (i >= 1 && candidates[i] == candidates[i - 1] && used[i - 1] == false) // 树层去重
            //     continue;
            if (set.find(candidates[i]) != set.end()) // 同一父节点下的同层上使用过的元素就不能再使用了
                continue;
            set.insert(candidates[i]);
            used[i] = true;
            path.push_back(candidates[i]);
            backtracking(i + 1, candidates, target, used, path, result); // 和39.组合总和的区别1：这里是i+1，因为每个数字在每个组合中只能使用一次
            path.pop_back();
            used[i] = false;
        }
    }
};
int main()
{
    Solution s;
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result = s.combinationSum2(candidates, 8);
    for (const auto &i : result)
    {
        for (const auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}