#include "../BinaryTree.h"    
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> result;
        vector<int> path;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                path.push_back(node->val);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            int max_num = *max_element(path.begin(), path.end());
            result.push_back(max_num);
            path.clear();
        }
        return result;
    }
};

int main()
{
    vector<int> arr = {1, 3, 2, 5, 3, -1, 9};
    TreeNode *root = createBinaryTree(arr);
    Solution solution;
    vector<int> result = solution.largestValues(root);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    delete root;
    return 0;
}