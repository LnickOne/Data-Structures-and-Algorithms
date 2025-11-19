/*
序列化二叉树的一种方法是使用 前序遍历 。当我们遇到一个非空节点时，我们可以记录下这个节点的值。
如果它是一个空节点，我们可以使用一个标记值记录，例如 #。
例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。
给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。
编写一个在不重构树的条件下的可行算法。
保证 每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。
你可以认为输入格式总是有效的
例如它永远不会包含两个连续的逗号，比如 "1,,3" 。
注意：不允许重建树。
示例 1:
输入: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
输出: true
示例 2:
输入: preorder = "1,#"
输出: false
示例 3:
输入: preorder = "9,#,#,1"
输出: false
*/
#include "../BinaryTree.h" 
class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int n = preorder.size();
        int degree = 1; // 初始化入度为 1，代表根节点
        for (int i = 0; i < n; ++i)
        {
            if (degree == 0)
            {
                return false; // 入度为 0 后还遇到节点，序列不合法
            }
            if (preorder[i] == ',')
            {
                continue; // 跳过逗号
            }
            if (preorder[i] == '#')
            {
                degree--; // 空节点，入度减 1
            }
            else
            {
                // 跳过非空节点的值
                while (i < n && preorder[i] != ',')
                {
                    i++;
                }
                degree--;    // 非空节点，入度减 1
                degree += 2; // 非空节点，出度加 2
            }
        }
        return degree == 0; // 最终入度为 0 则序列合法
    }
};