/*
一个 非严格递增排列 的数组 nums ，请 原地 删除重复出现的元素，使每个元素 只出现一次 ，
返回删除后数组的新长度。
元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。
nums 的其余元素与 nums 的大小不重要。
返回 k 。
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;
        int slow = 1;
        int fast = 1;
        while (fast < nums.size())
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                slow += 1;
            }
            fast += 1;
        }
        return slow;
    }
};

int main()
{
    vector<int> nums_1 = {1, 1, 2};
    vector<int> nums_2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums_3 = {1, 1, 2};
    int o_1 = Solution().removeDuplicates(nums_1);
    int o_2 = Solution().removeDuplicates(nums_2);
    int o_3 = Solution().removeDuplicates(nums_3);
    cout << o_1 << endl;
    cout << o_2 << endl;
    cout << o_3 << endl;
    return 0;
}