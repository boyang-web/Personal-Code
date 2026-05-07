/*完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，
其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第 h 层（从第 0 层开始），则该层包含 1~ 2h 个节点。*/

//拓展内容，伪代码写一写
/*
复杂度为n^2的就是正常的dfs计数

int dfs(treenode*)
{
    if(node==nullptr) return 0

    return 1+dfs(right)+dft(left)
}
但是考虑到完全二叉树必有一个子树是满二叉树
而满二叉树的节点数是pow(2,height)-1
就能写出这样的东西：
int dfs(treenode*)
{
    node* left,right=head;
    int nleft,nright
    while:
    left->next,nleft++
    while:
    right->next,nright++
    if(nleft==nright)
    return pow(2,nleft)-1


return 1+dfs(right)+dfs(left);
}
*/