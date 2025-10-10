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
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorder_recurision(root,result);
        return result;
    }
    void postorder_recurision(Node* root ,vector<int> &result){
        if(root==nullptr)
            return;
        for(auto child:root->children)
            postorder_recurision(child,result);
        result.push_back(root->val);
    }
};
