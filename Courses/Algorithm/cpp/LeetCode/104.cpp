// 二叉树最大深度
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

// 递归写法
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// 遍历写法
//写错了,depth会多加很多次，每一个节点都增加了
// void traverse(int &depth, TreeNode *node)
// {
//     if (node == nullptr)
//         return;
//     if (node->left != 0 || node->right != 0)
//         depth++;
//     traverse(depth, node->left);
//     traverse(depth, node->right);
// }

//正确的应该实时更新
int ans = 0;
int depth=0;
void traverse(TreeNode* node)
{
    if(node==nullptr) return ;
    
    depth++;
    if(node->left==nullptr&&node->right==nullptr)
    ans=max(ans,depth);
    traverse(node->left);
    traverse(node->right);
    //这一步最关键，模拟了退出节点时深度减小
    //展现了depth作为当前深度的作用
    depth--;
}

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        
        traverse(root);
        return ans;
    }
};