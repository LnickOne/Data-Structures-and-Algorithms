/* > 题目难度: 中等
> [原题链接](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
题目样例
示例
以下面的二叉搜索树为例：
![](https://assets.leetcode.com/uploads/2018/10/12/bstdlloriginalbst.png)
我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
下图展示了上面的二叉搜索树转化成的链表。"head" 表示指向链表中有最小元素的节点。
![](https://assets.leetcode.com/uploads/2018/10/12/bstdllreturndll.png)
特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。
题目思考
1. 如何确定当前节点在链表中的左右节点?
解决方案
方案 1
思路
- 根据题目描述, 一个比较容易想到的思路是分治法, 就是先将左右子树转换成双向链表, 然后再调节当前根节点的指向
- 双向链表需要知道其头和尾, 所以递归的返回值就是转换后的链表头和尾, 这样根节点左边就指向左子树对应链表的尾 ltail, 右边就指向右子树对应链表的头 rhead, 然后返回左边的头 lhead 和右边的尾 rtail, 自然就是当前的树转换后的链表头和尾了
- 注意如果当前根节点某一个子树不存在, 比如根节点只有左子树, 那么根节点右指针就不需要额外指向了, 且根节点就是对应的双向链表的尾. 而如果左右子树都不存在的话, 根节点本身就是对应的双向链表的头和尾. 这里可以将左右子树的头尾都初始化为 root 来实现 (具体参考下面的代码部分)
- 而递归出口自然就是节点为空的情况, 此时对应的链表头和尾都是空
- 这样递归调用, 最后返回的就是整个树转换成的链表的头和尾, 又因为题目要求是循环链表, 所以最后只需要把头尾相连即可
- 下面的代码对关键步骤都有详细的注释, 方便大家理解
复杂度
- 时间复杂度 `O(N)`
  - 每个节点只需要遍历一次
- 空间复杂度 `O(N)`
  - 递归栈的空间消耗

方案 2
思路
- 这次我们从另外一个角度分析这个问题
- 二叉搜索树的性质是中序遍历有序, 而最终形成的双向链表也是排好序的
- 所以我们可以直接利用中序遍历, 只需要额外存储一个 pre 节点, 然后遍历到当前节点时, 就将其和 pre 节点相连即可
- 另外遍历过程中要找到转换的链表的头和尾, 最后也要把它们也连起来从而形成循环链表
- 下面的代码对关键步骤都有详细的注释, 方便大家理解
复杂度
- 时间复杂度 `O(N)`
  - 每个节点只需要遍历一次
- 空间复杂度 `O(N)`
  - 递归栈的空间消耗
 */
#include "BinaryTree.h"

class Solution {
    TreeNode* pre = nullptr;  // previous node in in-order
    TreeNode* head = nullptr; // head of result list
public:
    TreeNode* treeToDoublyList(TreeNode* root) {
        if (!root) return nullptr;
        dfs(root);
        // make it circular
        head->left = pre;
        pre->right = head;
        return head;
    }
    void dfs(TreeNode* cur) {
        if (!cur) return;
        dfs(cur->left);
        if (pre) { pre->right = cur; cur->left = pre; }
        else head = cur;  // first node
        pre = cur;
        dfs(cur->right);
    }
};

int main() {
    TreeNode* root = createBinaryTree({4, 2, 5, 1, 3});
    Solution s;
    TreeNode* head = s.treeToDoublyList(root);
    // print first few nodes
    TreeNode* cur = head;
    for (int i = 0; i < 5; i++) { cout << cur->val << " "; cur = cur->right; }
    cout << endl;
    return 0;
}
