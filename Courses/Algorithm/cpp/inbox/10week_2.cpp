#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode *bulidtree()
{
    int x;
    if (!(cin >> x))
        return nullptr;
    if (x == -1)
        return nullptr;
    TreeNode *node = new TreeNode(x);
    node->left = bulidtree();
    node->right = bulidtree();
    return node;
}

int main()
{
    TreeNode *tree = bulidtree();
    queue<TreeNode *> q;
    q.push(tree);
    if (q.front() == nullptr)
        return 0;
    int maxwidth = 1;
    while (!q.empty())
    {
        int width = 1;
        int n=q.size();
        for (int i = 0; i < n; i++)
        {
            if (q.front()->left != nullptr && q.front()->left->val != -1)
                q.push(q.front()->left);
            if (q.front()->right != nullptr && q.front()->right->val != -1)
                q.push(q.front()->right);
            q.pop();
            width=q.size();
        }
        maxwidth = max(maxwidth, width);
    }
    cout << maxwidth;
    return 0;
}