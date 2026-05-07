#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    vector<TreeNode *> ans;
    set<int> to_del;

public:
    void traverse(TreeNode *tree)
    {
        if(tree==nullptr)
        return;
        TreeNode* left=tree->left;
        TreeNode* right=tree->right;
        if (to_del.count(tree->val))
        {
            if(tree->left!=nullptr)
            ans.push_back(tree->left);
            if(tree->right!=nullptr)
            ans.push_back(tree->right);
        }
        if(tree->left!=nullptr&&to_del.count(tree->left->val))
        {
            tree->left=nullptr;
        }
        if(tree->right!=nullptr&&to_del.count(tree->right->val))
        {
            tree->right=nullptr;
        }
        traverse(left);
        traverse(right);
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {

        for (int x : to_delete)
            to_del.insert(x);
        if (!to_del.count(root->val))
            ans.push_back(root);
        traverse(root);

        return ans;
    }
};