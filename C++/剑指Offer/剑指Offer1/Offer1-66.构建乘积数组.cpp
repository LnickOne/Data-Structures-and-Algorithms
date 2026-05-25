/* > 题目难度: 简单
> [原题链接](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/)
题目描述
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
- 所有元素乘积之和不会溢出 32 位整数
- a.length <= 100000
题目样例
示例
- 输入: [1,2,3,4,5]
- 输出: [120,60,40,30,24]
题目思考
1. 如何做到 O(N)时间复杂度?
解决方案
思路
- 一个比较容易想到的思路是暴力法, 对每个元素都计算其左右乘积, 这样时间复杂度达到了 O(N^2), 按照题目数据规模肯定会超时
- 还有种方法是求所有元素的总乘积, 然后对于每个元素分别除以自身 (注意对 0 的处理), 这样虽然只用了 O(N)时间, 但不满足题目要求
- 那如何做到 O(N)时间复杂度且不使用除法呢? 我们如果能够在计算某个元素时利用到之前的计算结果, 那么就不需要重复计算当前的左右所有乘积了
- 比较容易想到的思路就是类似前缀和的预处理方案, 只是这里改成了**前缀积**, 具体步骤如下:
  1. 从左到右遍历一遍数组, 记录当前前缀积并保存到数组中
  2. 然后再从右向左遍历, 记录当前后缀积, 然后与前一个前缀积相乘, 即为当前元素的左右所有元素乘积了
复杂度
- 时间复杂度 O(N): 只需要遍历数组两次
- 空间复杂度 O(N): 需要维护一个前缀积数组
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        int n = a.size();
        vector<int> b(n, 1);
        // 第一遍: 从左到右计算前缀积
        // b[i] 暂存 A[0]*A[1]*...*A[i-1]
        int prefix = 1;
        for (int i = 0; i < n; i++)
        {
            b[i] = prefix;
            prefix *= a[i];
        }
        // 第二遍: 从右到左乘以后缀积
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            b[i] *= suffix;
            suffix *= a[i];
        }
        return b;
    }
};

int main()
{
    Solution s;
    // 示例: [1,2,3,4,5] => [120,60,40,30,24]
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> result = s.constructArr(a);
    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < (int)result.size())
            cout << ",";
    }
    cout << endl; // 120,60,40,30,24
    return 0;
}
