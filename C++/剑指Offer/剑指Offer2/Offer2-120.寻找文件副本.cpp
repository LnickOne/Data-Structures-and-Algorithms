/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)
题目描述
设备中存有 n 个文件, 文件 id 记于数组 documents (0 <= documents[i] <= n-1)。请返回任一存在副本的文件 id。
题目样例
示例1
- 输入: documents=[2,5,3,0,5,0]
- 输出: 0 或 5
题目思考
1. 如何利用 0 <= documents[i] <= n-1 的条件, 实现 O(1) 空间?
解决方案
思路
- 遍历时将 documents[x%n] 加 n 作为标记; 若已被标记 (>=n) 则 x 即为重复值
- 利用值域 [0,n-1] 作为下标映射, 无需额外空间
复杂度
- 时间复杂度 O(N): 遍历一次
- 空间复杂度 O(1): 原地标记
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findRepeatDocument(vector<int> &documents)
    {
        int n = (int)documents.size();
        for (int x : documents)
        {
            if (x >= n)
                x -= n;
            if (documents[x] >= n)
                return x;
            documents[x] += n;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> d1 = {2, 5, 3, 0, 5, 0};
    cout << sol.findRepeatDocument(d1) << endl; // 0 或 5
    return 0;
}
