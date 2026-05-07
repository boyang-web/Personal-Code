#include <iostream>
#include <vector>
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
    int n1, n2;
    TreeNode *w1, *w2;
    vector<int> nums;

public:
    void traverse1(TreeNode *tree)
    {
        if (tree == nullptr)
            return;
        if (tree->left != nullptr)
            traverse1(tree->left);
        nums.push_back(tree->val);
        if (tree->right != nullptr)
            traverse1(tree->right);
    }
    void traverse2(TreeNode *tree)
    {
        if (tree == nullptr)
            return;
        if (tree->val == n1)
            w1 = tree;
        if (tree->val == n2)
            w2 = tree;
        if (tree->left != nullptr)
            traverse1(tree->left);
        if (tree->right != nullptr)
            traverse1(tree->right);
    }
    void recoverTree(TreeNode *root)
    {
        traverse1(root);
        // 找待换数
        for (int i = 1, j = 0; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1] && j == 0)
            {
                n1 = nums[i - 1];
                j = 1;
            }
            else if (nums[i] < nums[i - 1] && j == 1)
            {
                n2 = nums[i];
            }
        }
        traverse2(root);
        swap(w1->val, w2->val);
    }
};