#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
/*
给定一个无重复元素的整数数组nums，请你找出其中没有出现的最小的正整数

*/
class Solution
{
public:
    int minNumberDisappeared(vector<int> &nums)
    {
        map<int, int> map;
        for (int num : nums)
            map[num]++;
        int result=1;

        while(map.find(result)!=map.end())
            result++;
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 0};
    Solution s;
    cout << s.minNumberDisappeared(nums);
    return 0;
}