/*有一个 n×m 的棋盘，在某个点 (x,y) 上有一个马，要求你计算出马到达棋盘上任意一个点最少要走几步。

输入格式
输入只有一行四个整数，分别为 n,m,x,y。

输出格式
一个 n×m 的矩阵，代表马到达某个点最少要走几步（不能到达则输出 −1）。

输入输出样例
输入 #1复制

3 3 1 1
输出 #1复制

0 3 2
3 -1 1
2 1 4
说明/提示
数据规模与约定
对于全部的测试点，保证 1≤x≤n≤400，1≤y≤m≤400*/

// 最短路径，这是bfs
#include <iostream>
#include <queue>
using namespace std;
// 全局变量
int dist[410][410];
queue<pair<int, int>> nodeq;

int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[] = {2, 2, 1, -1, -2, -2, -1, 1};

int main()
{
    for (int i = 0; i < 410; i++)
        for (int j = 0; j < 410; j++)
            dist[i][j] = -1;
    int n, m, x0, y0;
    cin >> n >> m >> x0 >> y0;
    // 初始化
    nodeq.push({x0, y0});
    dist[x0][y0] = 0;

    while (!nodeq.empty())
    {
        pair<int, int> cur = nodeq.front();
        nodeq.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (cur.first >= 1 && cur.first <= n && cur.second >= 1 && cur.second <= m && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                nodeq.push({nx, ny});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << dist[i][j] << " ";
        cout << "\n";
    }

    return 0;
}