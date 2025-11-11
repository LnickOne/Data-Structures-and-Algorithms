/*
给你一个整数数组 arr，如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
示例 1：
输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
示例 2：
输入：arr = [1,2]
输出：false
示例 3：
输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> map_key;
        unordered_map<int, int> map_val;
        for (const int &key : arr)
            map_key[key]++;
        // for (auto iter = map_key.begin(); iter != map_key.end(); ++iter)
        // {
        //     ++map_val[iter->second];
        //     if (map_val[iter->second] > 1)
        //         return false;
        // }
        for (const auto &iter : map_key)
        {
            ++map_val[iter.second];
            if (map_val[iter.second] > 1)
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    Solution app;
    bool result = app.uniqueOccurrences(arr);
    cout << result << endl;
    return 0;
}