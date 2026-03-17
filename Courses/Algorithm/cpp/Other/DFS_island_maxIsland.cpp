// 求最大岛屿面积 虽然跟上一题区别不大，但是还是重写一遍增加熟练度
// 1是岛0是海

#include <iostream>
#include <algorithm>
using namespace std;
// 全局变量
int m, n;
char grid[10][10];
bool visited[10][10] = {false};
int area = 0;
int maxarea = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    visited[x][y] = true;
    area++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        //同样的错误,char数组比较对象需要加单引号
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1' && !visited[nx][ny])
            dfs(nx, ny);
    }
}

int main()
{
    // 输入部分
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // dfs
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])//这一句居然忘记写了。
            {
                area = 0;
                dfs(i, j);
                maxarea = max(maxarea, area);
            }
        }
    }
    cout << maxarea;
    return 0;
}