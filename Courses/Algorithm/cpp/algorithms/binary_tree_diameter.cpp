/*
给你一棵二叉树的根节点，返回该树的 直径 。

二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

两节点之间路径的 长度 由它们之间边数表示。
*/

// 实际上就是把每个节点的两个子最大深度加起来，再取最大值
#include <vector>
#include <queue>
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

// 实时计算子节点最大长度，效率很低
class Solution
{
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        traverse(root);
        return ans;
    }

    int getMaxDepth(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(getMaxDepth(node->left), getMaxDepth(node->right));
    }

    void traverse(TreeNode *node)
    {
        if (node == nullptr)
            return;
        ans = max(ans, getMaxDepth(node->left) + getMaxDepth(node->right));
        traverse(node->left);
        traverse(node->right);
    }
};

// 后序写法，更改traverse函数，返回当前最大深度即可

class Solution
{
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        depth(root);
        return ans;
    }
    int depth(TreeNode* node)
    {
        if(node==nullptr) return 0;

        int L=depth(node->left);
        int R=depth(node->right);
        ans=max(ans,L+R);
        return 1+max(L,R);
    }
};