/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/NaqhDT/)
题目描述
设计完全二叉树插入器 CBTInserter, 初始化时传入完全二叉树根节点 root:
- insert(int v): 插入新节点并返回其父节点的值, 保持完全二叉树状态
- get_root(): 返回树的根节点
题目样例
示例1
- 输入: ["CBTInserter","insert","get_root"] [[[1]],[2],[]]
- 输出: [null,1,[1,2]]
示例2
- 输入: ["CBTInserter","insert","insert","get_root"] [[[1,2,3,4,5,6]],[7],[8],[]]
- 输出: [null,3,4,[1,2,3,4,5,6,7,8]]
题目思考
1. 如何利用完全二叉树的性质?
解决方案
思路
- BFS 按层存储所有节点到 levels 二维数组
- 完全二叉树第 h 层 (从 0 开始) 满时节点数为 2^h
- 插入时: 若最后一层满则新建一层, 待插入节点的父节点下标为 当前层大小/2 (在上一层中)
- 判断左子节点是否为空决定插入左还是右
复杂度
- 时间复杂度 O(1): 每次 insert 只需要常数次操作
- 空间复杂度 O(N): 存储所有节点
 */
#include "../剑指Offer1/BinaryTree.h"
#include <vector>

class CBTInserter
{
    TreeNode *root;
    vector<vector<TreeNode *>> levels;
public:
    CBTInserter(TreeNode *r) : root(r)
    {
        queue<TreeNode *> q;
        q.push(r);
        while (!q.empty())
        {
            int sz = q.size();
            vector<TreeNode *> layer;
            for (int i = 0; i < sz; i++)
            {
                auto node = q.front(); q.pop();
                layer.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levels.push_back(layer);
        }
    }
    int insert(int v)
    {
        int h = levels.size() - 1;
        if ((int)levels.back().size() == (1 << h))
            levels.push_back({});
        int pi = levels.back().size() / 2;
        TreeNode *parent = levels[levels.size() - 2][pi];
        TreeNode *node = new TreeNode(v);
        if (!parent->left) parent->left = node;
        else parent->right = node;
        levels.back().push_back(node);
        return parent->val;
    }
    TreeNode *get_root() { return root; }
};

int main()
{
    // 示例1: [1] 插入 2
    TreeNode *r1 = createBinaryTree({1});
    CBTInserter c1(r1);
    cout << c1.insert(2) << endl; // 1
    // 示例2: [1,2,3,4,5,6] 插入 7, 8
    TreeNode *r2 = createBinaryTree({1, 2, 3, 4, 5, 6});
    CBTInserter c2(r2);
    cout << c2.insert(7) << endl; // 3
    cout << c2.insert(8) << endl; // 4
    delete r1;
    delete r2;
    return 0;
}
