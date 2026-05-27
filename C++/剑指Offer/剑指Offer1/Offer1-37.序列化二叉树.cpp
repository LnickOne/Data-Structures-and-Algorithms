/* > 题目难度: 困难
> [原题链接](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树。
题目样例
示例
你可以将以下二叉树：
```
    1
   / \
  2   3
     / \
    4   5
```
序列化为 "[1,2,3,null,null,4,5]"
题目思考
1. 如何定位节点之间的关系?
解决方案
思路
- 既然题目没有限制序列化和反序列化的算法, 我们就怎样简单怎样来
- 如果我们给每个节点一个唯一的下标, 同时保存它的父节点下标, 以及父节点对当前节点的指向(即左还是右子节点), 当然还有节点本身的值, 这样就能唯一确定整棵树了
- 根据这个思路, 我们序列化的时候就可以使用 BFS, 用一个四元组保存上述信息, 最后转成字符串即可
- 反序列化就更简单了: 使用字典保存下标到值的映射关系(下标唯一), 因为保存的时候是 BFS 逐层遍历的, 所以当要转换某个节点时, 其父节点一定已经转换好并保存在字典中了, 这样就能拿到父节点, 再根据指向决定当前是左还是右子节点即可
- 下面的代码对必要的步骤都有详细的解释, 方便大家理解
复杂度
- 时间复杂度 `O(N)`
  - 每个节点只需要遍历一次
- 空间复杂度 `O(N)`
  - 队列的消耗, 因为是四元组, 所以是 `O(4*N) = O(N)`
 */
#include "BinaryTree.h"
#include <sstream>
class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node)
            {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                res += "null,";
            }
        }
        return res;
    }

    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;
        vector<string> vals;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ','))
            if (!item.empty())
                vals.push_back(item);
        TreeNode *root = new TreeNode(stoi(vals[0]));
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < (int)vals.size())
        {
            TreeNode *node = q.front();
            q.pop();
            if (vals[i] != "null")
            {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;
            if (i < (int)vals.size() && vals[i] != "null")
            {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

int main()
{
    TreeNode *root = createBinaryTree({1, 2, 3, 4, 5});
    Codec codec;
    string s = codec.serialize(root);
    cout << s << endl;
    TreeNode *root2 = codec.deserialize(s);
    cout << codec.serialize(root2) << endl;
    return 0;
}
