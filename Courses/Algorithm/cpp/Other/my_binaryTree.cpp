/*实现一下二叉树的读入
用队列模拟，# 代表空位置
比如1 2 3 4 # 5 #
*/
#include<iostream>
#include<string>
#include<queue>
#include<fstream>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};
void writefile()
{
    ofstream fout("tempfile/mytree.txt");
    fout<<"1 2 3 4 5 # 7";
    fout.close();
}

TreeNode* readtree()
{
    ifstream fin("tempfile/mytree.txt");
    string headn;
    if(!(fin>>headn)||headn=="#");//注意这个读入
    TreeNode* head=new TreeNode(stoi(headn));
    queue<TreeNode*> q;
    q.push(head);
    while(!q.empty())
    {
        string leftn,rightn;
        fin>>leftn>>rightn;
        if(leftn!="#")
        {
            TreeNode* leftnode=new TreeNode(stoi(leftn));
            q.front()->left=leftnode;
            q.push(leftnode);
        }
        if(rightn!="#")
        {
            TreeNode* rightnode=new TreeNode(stoi(rightn));
            q.front()->right=rightnode;
            q.push(rightnode);
        }
        q.pop();
    }
    fin.close();
    return head;
}