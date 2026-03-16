//二叉树最小深度
//虽然已经写了最大深度，但是还是复习一下最小深度
//最小深度层序遍历会更简单
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

//递归遍历
class Solution {
public:
    int ans=1000000;
    int depth=0;
    void traverse(TreeNode* node)
    {
        if(node==nullptr) return;

        depth++;
        if(node->left==nullptr&&node->right==nullptr)
        ans=min(depth,ans);
        traverse(node->left);
        traverse(node->right);
        depth--;
    }

    int minDepth(TreeNode* root) {//注意极端情况
        if(root==nullptr) return 0;
        traverse(root);
        return ans;
    }
};

//层序遍历
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        queue<TreeNode*> tree;
        int depth=1;
        tree.push(root);
        while(!tree.empty())
        {
            int n=tree.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* front=tree.front();
                tree.pop();
                //这里把||改成&&就过了，注意最小深度需要在严格叶子节点产生
                if(front->left==nullptr&&front->right==nullptr)
                return depth;
                if(front->left!=nullptr)
                tree.push(front->left);
                if(front->right!=nullptr)
                tree.push(front->right);
            }
            depth++;
        }
        return depth;
    }
};