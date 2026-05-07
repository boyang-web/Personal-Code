// 最小枝长

#include <iostream>
#include <map>
#include <climits>
#include<set>
using namespace std;

map<int, pair<int, int>> nodes;
struct TreeNode
{
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

TreeNode *buildtree(int k)
{
    TreeNode *node = new TreeNode;
    if (nodes[k].first == 0 && nodes[k].second == 0)
        return node;
    if (nodes[k].first != 0)
        node->left = buildtree(nodes[k].first);
    if (nodes[k].second != 0)
        node->right = buildtree(nodes[k].second);
    return node;
}

int ans = INT_MAX;
void Traverse(TreeNode *tree, int depth)
{

    if (tree == nullptr)
        return;
    if (tree->left == nullptr && tree->right == nullptr)
        ans = min(depth, ans);
    if (tree->left != nullptr)
        Traverse(tree->left, depth + 1);
    if (tree->right != nullptr)
        Traverse(tree->right, depth + 1);
}

int main()
{
    int n;
    cin >> n;
    map<int,int> cnt;
    for (int i = 0; i < n; i++)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        cnt[n1]++;
        cnt[n2]++;
        cnt[n3]++;
    
        nodes[n1] = {n2, n3};
    }
    int root;
    for(auto x:cnt)
    {
        if(x.second==1)
        root=x.first;
    }
    
    TreeNode *tree = buildtree(root);
    Traverse(tree, 0);
    cout << ans;

    return 0;
}
