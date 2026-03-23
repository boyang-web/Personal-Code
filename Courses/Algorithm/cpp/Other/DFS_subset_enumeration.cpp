/*枚举集合的子集
这个题就基本上是二叉决策树的dfs了

*/

#include <vector>
#include<iostream>

using namespace std;

vector<int> s = {2, 1, 3};
vector<int> path;   // 存储子集
void dfs(int index) // 决策当前index选不选
{
    // 递归结束条件
    if (index == s.size())
    {
        for (int x : path)
            cout << x << " ";
        cout << "\n";
        return ;
    }
    dfs(index + 1); // 不选

    path.push_back(s[index]); // 选
    dfs(index + 1);
    path.pop_back();
}

int main()
{

    dfs(0);
    return 0;
}