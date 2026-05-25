/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/h54YBf/)
题目描述
请设计一个算法实现二叉树的序列化与反序列化。
序列化是将数据结构转换为可存储/传输的字符串格式; 反序列化是将字符串还原为原始数据结构。
题目样例
示例1
- 输入: root = [1,2,3,null,null,4,5]
- 输出: [1,2,3,null,null,4,5]
示例2
- 输入: root = []
- 输出: []
题目思考
1. 如何定位节点之间的关系?
解决方案
思路
- 序列化: BFS 按层遍历, 输出节点值和 null (用 # 表示), 用空格分隔
- 反序列化: 用队列记录已创建节点, 按顺序读取值为每个节点分配左右子节点
复杂度
- 时间复杂度 O(N): 每个节点只需要遍历一次
- 空间复杂度 O(N): 队列空间
 */
#include "BinaryTree.h"
#include <string>
#include <sstream>

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (!root) return "#";
        string res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front(); q.pop();
            if (node)
            {
                res += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                res += "# ";
            }
        }
        return res;
    }
    TreeNode *deserialize(string data)
    {
        if (data == "#") return nullptr;
        istringstream ss(data);
        string tok;
        ss >> tok;
        TreeNode *root = new TreeNode(stoi(tok));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front(); q.pop();
            if (ss >> tok && tok != "#")
            {
                node->left = new TreeNode(stoi(tok));
                q.push(node->left);
            }
            if (ss >> tok && tok != "#")
            {
                node->right = new TreeNode(stoi(tok));
                q.push(node->right);
            }
        }
        return root;
    }
};

int main()
{
    Codec codec;
    auto r1 = createBinaryTree({1, 2, 3, -1, -1, 4, 5});
    string s1 = codec.serialize(r1);
    cout << s1 << endl; // 1 2 3 # # 4 5 ...
    auto r1b = codec.deserialize(s1);
    cout << codec.serialize(r1b) << endl; // same
    delete r1; delete r1b;
    // 空树
    string s2 = codec.serialize(nullptr);
    cout << s2 << endl; // #
    cout << (codec.deserialize(s2) == nullptr ? "null" : "non-null") << endl; // null
    return 0;
}
