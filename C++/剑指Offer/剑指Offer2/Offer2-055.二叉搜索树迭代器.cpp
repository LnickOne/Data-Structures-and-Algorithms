/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/kTOapQ/)
题目描述
实现二叉搜索树迭代器 BSTIterator:
- BSTIterator(TreeNode *root): 初始化, 指针指向比 BST 最小元素还小的数字
- bool hasNext(): 指针右侧是否有数字
- int next(): 指针右移并返回指针处的数字
题目样例
示例1
- 输入: ["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
         [[[7,3,15,null,null,9,20]],[],[],[],[],[],[],[],[],[]]
- 输出: [null,3,7,true,9,true,15,true,20,false]
题目思考
1. 如何利用二叉搜索树的性质?
2. 如何使 next() 和 hasNext() 均摊时间复杂度为 O(1)?
解决方案
思路
- 用显式栈模拟中序遍历: 始终将当前节点及其所有左子节点压栈
- next(): 弹出栈顶节点取值, 然后将其右子节点及右子节点的所有左子节点压栈
- hasNext(): 栈非空则有下一个
- 均摊 O(1) 时间, O(H) 空间
复杂度
- 时间复杂度 O(1) (均摊): 每个节点入栈出栈各一次
- 空间复杂度 O(H): 栈最多存树高度个节点
 */
#include "BinaryTree.h"
#include <stack>

class BSTIterator
{
    stack<TreeNode *> st;
    void pushLeft(TreeNode *node)
    {
        while (node) { st.push(node); node = node->left; }
    }
public:
    BSTIterator(TreeNode *root) { pushLeft(root); }
    int next()
    {
        TreeNode *node = st.top(); st.pop();
        pushLeft(node->right);
        return node->val;
    }
    bool hasNext() { return !st.empty(); }
};

int main()
{
    cout << boolalpha;
    TreeNode *r = createBinaryTree({7, 3, 15, -1, -1, 9, 20});
    BSTIterator it(r);
    cout << it.next() << endl;    // 3
    cout << it.next() << endl;    // 7
    cout << it.hasNext() << endl; // true
    cout << it.next() << endl;    // 9
    cout << it.hasNext() << endl; // true
    cout << it.next() << endl;    // 15
    cout << it.hasNext() << endl; // true
    cout << it.next() << endl;    // 20
    cout << it.hasNext() << endl; // false
    delete r;
    return 0;
}
