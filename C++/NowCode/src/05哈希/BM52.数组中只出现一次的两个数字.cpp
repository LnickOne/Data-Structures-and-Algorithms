#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
/*
一个整型数组里除了两个数字只出现一次，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/
class Solution
{
public:
    vector<int> FindNumsAppearOnce(vector<int> &nums)
    {
        map<int, int> map;
        vector<int> result;
        int key;
        int val;
        for (int i = 0; i < nums.size(); i++)
        {
            key = nums[i];
            map[key]++;
        }
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second == 1)
            {
                result.push_back(it->first);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}