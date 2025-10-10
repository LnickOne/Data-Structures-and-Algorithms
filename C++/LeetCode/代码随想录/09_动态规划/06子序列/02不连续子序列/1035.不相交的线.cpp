#include <vector>
#include <iostream>
using namespace std;
/**
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足：
nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
以这种方法绘制线条，并返回可以绘制的最大连线数。
示例 1：
输入：nums1 = [1,4,2], nums2 = [1,2,4]
输出：2
解释：可以画出两条不交叉的线，如上图所示。
但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2 的直线相交。
示例 2：
输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
输出：3
示例 3：
输入：nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
输出：2
 */
class Solution
{
public:
    /*
    动态规划五部曲
    1.确定DP数组的含义
    dp[i][j]表示可以绘制的最大连线数
    2.确定递推公式
    dp[i][j]表示nums1[0,i-1]和nums2[0,j-1]的最长公共子序列长度
    if (nums1[i-1]==nums2[j-1])
        dp[i][j] = dp[i-1][j-1]+1
    else max(dp[i-1][j],dp[i][j-1])
    3.初始化DP数组
    dp[i][j]=0
    4.确定遍历顺序
    从前往后
    5.打印dp数组
    */
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int result = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                if (nums1[i - 1] != nums2[j - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums1_1 = {1, 4, 2}, nums1_2 = {1, 2, 4};
    vector<int> nums2_1 = {2, 5, 1, 2, 5}, nums2_2 = {10, 5, 2, 1, 5, 2};
    vector<int> nums3_1 = {1, 3, 7, 1, 7, 5}, nums3_2 = {1, 9, 2, 5, 1};
    Solution s;
    cout << s.maxUncrossedLines(nums1_1, nums1_2) << endl;
    cout << s.maxUncrossedLines(nums2_1, nums2_2) << endl;
    cout << s.maxUncrossedLines(nums3_1, nums3_2) << endl;
    return 0;
}