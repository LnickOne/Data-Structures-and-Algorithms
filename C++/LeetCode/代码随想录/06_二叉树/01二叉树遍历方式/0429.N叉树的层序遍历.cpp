#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;
    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
    ~Node()
    {
        for (auto child : children)
        {
            delete child;
        }
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
            return {};
        vector<vector<int>> result;
        queue<Node *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            vector<int> path;
            for (int i = 0; i < size; i++)
            {
                Node *node = queue.front();
                queue.pop();
                path.push_back(node->val);
                for (auto child : node->children)
                    queue.push(child);
            }
            result.push_back(path);
        }
        return result;
    }
};

int main()
{
    // 构建一个简单的 N 叉树
    //       1
    //     / | \
    //    3  2  4
    //   / \
    //  5   6
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node3 = new Node(3, {node5, node6});
    Node *node2 = new Node(2);
    Node *node4 = new Node(4);
    Node *root = new Node(1, {node3, node2, node4});

    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    // 输出层序遍历结果
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // 根节点的析构函数会递归释放所有子节点
    delete root;
    return 0;
}