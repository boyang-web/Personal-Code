#include <string>
#include <iostream>

using namespace std;

string input;
int pos = 0;
struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode *buildtree()
{
    TreeNode *node=new TreeNode(input[pos]);
    pos++;

    if(pos<input.size()&&input[pos]=='(')
    {
        if(pos<input.size()&&input[pos]!=')'&&input[pos]!=',')
        {
            node->left=buildtree();
        }
        if(pos<input.size()&&input[pos]==',')
        {
            pos++;
            if(pos<input.size()&&input[pos]!=')')
            {
                node->right=buildtree();
            }
        }
        if(pos<input.size()&&input[pos]==')')
        {
            pos++;
        }
    }
    
    return node;
}

void output_children(TreeNode *tree)
{
    if(tree==nullptr)
    return ;
    if (tree->left == nullptr && tree->right == nullptr )
        cout << tree->val << " ";
    
    output_children(tree->right);
    output_children(tree->left);
}

int main()
{
    getline(cin, input);
    TreeNode *tree = buildtree();
    output_children(tree);
    return 0;
}
