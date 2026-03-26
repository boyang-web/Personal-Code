/*给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，
其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第 h 层（从第 0 层开始），则该层包含 1~ 2h 个节点。

 */
#include <cmath>

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
public:
    int countNodes(TreeNode *root)
    {
        TreeNode *pleft = root, *pright = root;
        int nleft = 0, nright = 0;
        while (pleft != nullptr)
        {
            pleft = pleft->left;
            nleft++;
        }
        while (pright != nullptr)
        {
            pright = pright->right;
            nright++;
        }
        if (nleft == nright)
            return pow(2, nleft) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};