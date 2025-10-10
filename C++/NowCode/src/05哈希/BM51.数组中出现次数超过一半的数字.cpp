#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
描述
给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
*/

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> &numbers)
    {
        int frequency = numbers.size() / 2;
        unordered_map<int, int> map;
        for (int num : numbers)
        {
            map[num]++;
            if (map[num] > frequency)
                return num;
        }
        return 0;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Solution s;
    cout << s.MoreThanHalfNum_Solution(nums) << endl;
    return 0;
}