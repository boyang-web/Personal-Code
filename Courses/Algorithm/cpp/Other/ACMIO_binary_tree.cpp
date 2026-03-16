/*
给定一棵二叉树，计算它的前序、中序、后序遍历结果。
树的结构以边的形式给出：
树上共有 n 个节点，编号为 1 到 n，其中节点 1 是根节点。
输入一个长度为 n 的数组 values，其中 values[i] 代表节点 i+1 的值。
同时输入一个 edges 数组，其中每个元素 [u, v] 表示节点 u 和节点 v 之间有一条边。
对于每个节点，按照 edges 数组中边出现的顺序来确定子节点的顺序，
先出现的节点作为左子节点，后出现的节点作为右子节点。
 
edges 数组长度为 
n−1，保证构成一棵合法的树
保证输入的树是一棵二叉树（每个节点最多有 2 个子节点）
输入格式
第一行输入一个正整数 n，代表节点数量。
第二行输入 n 个整数，空格分隔，代表 values 数组（节点 1 到 n 的值）。
接下来 n-1 行，每行输入 2 个正整数 u 和 v，代表节点 u 和节点 v 之间有一条边。

输出格式

三行，每行为空格分隔的整数：

第一行为前序遍历结果
第二行为中序遍历结果
第三行为后序遍历结果
示例输入
5
10 20 30 40 50
1 2
1 3
2 4
2 5

示例输出
10 20 40 50 30
40 20 50 10 30
40 50 20 30 10
解释：树的结构为：
      1(10)
     /    \
   2(20)  3(30)
   /  \
 4(40) 5(50)
前序遍历（根→左→右）：10 → 20 → 40 → 50 → 30
中序遍历（左→根→右）：40 → 20 → 50 → 10 → 30
后序遍历（左→右→根）：40 → 50 → 20 → 30 → 10
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// -- core code template start
class Solution {
public:
    vector<vector<int>> treeTraversal(vector<int>& values, vector<vector<int>>& edges) {

    }

private:
    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<int>& values, vector<int>& preorder, 
             vector<int>& inorder, vector<int>& postorder) {
        preorder.push_back(values[node - 1]);
        
        vector<int> children;
        for (int child : adj[node]) {
            if (child != parent) {
                children.push_back(child);
            }
        }
        
        if (children.size() > 0) {
            dfs(children[0], node, adj, values, preorder, inorder, postorder);
        }
        
        inorder.push_back(values[node - 1]);
        
        if (children.size() > 1) {
            dfs(children[1], node, adj, values, preorder, inorder, postorder);
        }
        
        postorder.push_back(values[node - 1]);
    }
};
// -- core code template end

int main() {
    int n;
    while (cin >> n) {
        vector<int> values(n);
        cin.ignore();
        string line;
        getline(cin, line);
        istringstream iss(line);
        for (int i = 0; i < n; i++) {
            iss >> values[i];
        }

        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        vector<vector<int>> result = Solution().treeTraversal(values, edges);

        for (int i = 0; i < result[0].size(); i++) {
            if (i > 0) cout << " ";
            cout << result[0][i];
        }
        cout << endl;
        for (int i = 0; i < result[1].size(); i++) {
            if (i > 0) cout << " ";
            cout << result[1][i];
        }
        cout << endl;
        for (int i = 0; i < result[2].size(); i++) {
            if (i > 0) cout << " ";
            cout << result[2][i];
        }
        cout << endl;

    }
    return 0;
}