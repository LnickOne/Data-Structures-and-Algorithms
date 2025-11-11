/*
给你两个长度相等的整数数组，返回下面表达式的最大值：
|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
其中下标 i，j 满足 0 <= i, j < arr1.length。
示例 1：
输入：arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
输出：13
示例 2：
输入：arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
输出：20
提示：
2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                res = max(res, abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j));
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {-1, 4, 5, 6};
    int res = s.maxAbsValExpr(arr1, arr2);
    cout << res << endl;
    return 0;
}