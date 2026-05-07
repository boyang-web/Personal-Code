// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
//  （即逐层地，从左到右访问所有节点）。
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
// 一开始写错了：没看清返回类型，如果返回的东西还要包含层信息
// 那么就在此基础上修改一下，遍历完一层就记录一层
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<int> ans;
//         queue<TreeNode*> tree;
//         tree.push(root);
//         while(!tree.empty())
//         {
//             TreeNode* front=tree.front();
//             if(front->left!=nullptr)
//             tree.push(front->left);
//             if(front->right!=nullptr)
//             tree.push(front->right);
//             ans.push_back(front->val);
//             tree.pop();
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> tree;
        tree.push(root);
        while (!tree.empty())
        {
            int n = tree.size();
            vector<int> layer;
            for (int i = 0; i < n; i++)
            {
                
                TreeNode *front = tree.front();
                tree.pop();
                layer.push_back(front->val);
                if (front->left != nullptr)
                    tree.push(front->left);
                if (front->right != nullptr)
                    tree.push(front->right);
                
                
            }
            //注意各个语句写在哪一层
            ans.push_back(layer);
        }
        return ans;
    }
};