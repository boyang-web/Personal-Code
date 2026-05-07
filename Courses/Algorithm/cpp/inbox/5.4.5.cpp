#include <iostream>
#include <map>
using namespace std;

struct TreeNode
{
    char c;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(char ch) : c(ch) {}
};
map<char, pair<char, char>> nodes;
char target;

TreeNode *buildtree(char c)
{
    TreeNode *node = new TreeNode(c);
    if (nodes[c].first != '#')
        node->left = buildtree(nodes[c].first);
    if (nodes[c].second != '#')
        node->right = buildtree(nodes[c].second);
    return node;
}

bool is_target = false;
void traverse(TreeNode *tree)
{
    if (tree == nullptr)
        return;
    if (is_target)
        cout << tree->c << " ";
    if (tree->c == target)
        is_target = true;
    if (tree->left != nullptr)
        traverse(tree->left);
    if (tree->right != nullptr)
        traverse(tree->right);
    if (tree->c == target)
        is_target = false;
}

int main()
{
    int n;
    cin >> n;
    map<char, char> findroot;
    for (int i = 0; i < n; i++)
    {
        char c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        findroot[c1]++;
        findroot[c2]++;
        findroot[c3]++;
        nodes[c1] = {c2, c3};
    }
    cin >> target;
    char root;
    for (auto x : findroot)
    {
        if (x.second == 1)
            root = x.first;
    }
    TreeNode *tree = buildtree(root);
    traverse(tree);
    return 0;
}