/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
中序后序的递归写法都类似
*/
#include<vector>
using namespace std;
 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

//递归写法

//需要一个辅助函数traverse来往数组里塞数
void traverse(vector<int> &v,TreeNode* node)
{
    //受不了了，再一次==写成=了
    if(node==nullptr) return ;
    v.push_back(node->val);
    traverse(v,node->left);
    traverse(v,node->right);
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans={};
        traverse(ans , root);
        return ans;
    }
};


//迭代写法