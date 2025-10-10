#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(const vector<int> &nums)
    {
        if (nums.empty())
            return {};
        vector<int> result;
        unordered_map<int, int> map;
        for (const int &num : nums)
            ++map[num];
        const int frequency = nums.size() / 3;
        for (const auto &iter : map)
            if (iter.second > frequency)
                result.push_back(iter.first);
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 2, 3};
    vector<int> result = s.majorityElement(nums);
    for (const int &num : result)
        cout << num << endl;
    return 0;
}