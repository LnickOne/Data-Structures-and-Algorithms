/* > 题目难度: 中等
> [原题链接](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/)
题目描述
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
- 0 < nums.length <= 100
- 输出结果可能非常大，所以你需要返回一个字符串而不是整数
- 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
题目样例
示例
- 输入: [10,2]
- 输出: "102"
- 输入: [3,30,34,5,9]
- 输出: "3033459"
题目思考
1. 怎么定义最小?
解决方案
思路
- 分析题目, 要使得拼接起来的数字最小, 只有当各个拼接元素按照从小到大拼接起来才可以
- 而这里的从小到大拼接, 不是指按照数字本身顺序或者字典序从小到大拼接
- 举个例子, 90 和 902 的拼接结果应该是 90290, 但是 90 不管是数字还是字典序都小于 902
- 那如何定义哪个数字作为拼接后的第一个数字呢?
- 假如这个数字和任意其他数字拼接起来, 都小于将两个数字互换后拼接的结果, 那么显然这个数字就应该放在首位
- 到这里就知道了, 我们应该自定义一个排序方法, 对于两个数字 a 和 b 而言, 比较 `str(a)+str(b)` 与 `str(b)+str(a)` 的大小关系, 然后对整个列表排序后组成一个字符串即可
复杂度
- 时间复杂度 `O(NlogN)`
  - 排序的时间复杂度
- 空间复杂度 `O(N)`
  - 使用了额外的字符串数组
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string minNumber(vector<int> &nums)
    {
        // 将所有数字转为字符串
        vector<string> strs;
        for (int num : nums)
            strs.push_back(to_string(num));

        // 自定义排序: 比较 a+b 与 b+a, 若 a+b < b+a 则 a 排在前面
        sort(strs.begin(), strs.end(), [](const string &a, const string &b)
             { return a + b < b + a; });

        // 拼接所有字符串
        string res;
        for (const string &str : strs)
            res += str;

        return res;
    }
};

int main()
{
    Solution s;

    // 示例: [10,2] => "102"
    vector<int> nums1 = {10, 2};
    cout << "输入 [10,2] => " << s.minNumber(nums1) << endl;

    // 示例: [3,30,34,5,9] => "3033459"
    vector<int> nums2 = {3, 30, 34, 5, 9};
    cout << "输入 [3,30,34,5,9] => " << s.minNumber(nums2) << endl;

    return 0;
}
