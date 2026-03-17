/*
题目背景
oibh 总部突然被水淹没了！现在需要你的救援……

题目描述
oibh 被突来的洪水淹没了，还好 oibh 总部有在某些重要的地方起一些围墙。
用 * 号表示，而一个四面被围墙围住的区域洪水是进不去的。

oibh 总部内部也有许多重要区域，每个重要区域在图中用一个 0 表示。

现在给出 oibh 的围墙建设图，问有多少个没被洪水淹到的重要区域。

输入格式
第一行为两个正整数 x,y。

接下来 x 行，每行 y 个字符，由 * 和 0 组成，表示 oibh 总部的建设图。

输出格式
输出没被水淹没的 oibh 总部的 0 的数量。
*/

// 实际上就是岛屿问题，但是只用遍历四条边

#include <iostream>

using namespace std;
// 全局变量
int x, y;
char grid[510][510];
bool visited[510][510] = {false};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int cnt = 0;

void dfs(int lx,int ly)
{
    if(grid[lx][ly]=='*') return;
    visited[lx][ly]=true;
    for(int i=0;i<4;i++)
    {
        int nx=lx+dx[i];
        int ny=ly+dy[i];
        if(nx>=0&&ny>=0&&nx<x&&ny<y&&grid[nx][ny]=='0'&&!visited[nx][ny])
        dfs(nx,ny);
    }
}

int main()
{
    // 输入
    cin >> x >> y;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> grid[i][j];
        }
    }

    // dfs
    for (int i = 0; i < x; i++)
    {
        dfs(i, 0);
        dfs(i, y - 1);
    }
    for (int i = 0; i < y; i++)
    {
        dfs(0, i);
        dfs(x - 1, i);
    }

    // 统计
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
            if (visited[i][j] == false && grid[i][j] == '0')
                cnt++;
    }
    cout << cnt;
    return 0;
}