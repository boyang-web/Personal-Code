// 网格取数
/*一个 N×M 的由非负整数构成的数字矩阵，你需要在其中取出若干个数字，
使得取出的任意两个数字不相邻（若一个数字在另外一个数字相邻 8 个格子中的一个即认为这两个数字相邻），
求取出数字和最大是多少。

输入格式
第一行有一个正整数 T，表示了有 T 组数据。
对于每一组数据，第一行有两个正整数 N 和 M，表示了数字矩阵为 N 行 M 列。
接下来 N 行，每行 M 个非负整数，描述了这个数字矩阵。
输出格式
共 T 行，每行一个非负整数，输出所求得的答案。
输入输出样例
输入 #1复制

3
4 4
67 75 63 10
29 29 92 14
21 68 71 56
8 67 91 25
2 3
87 70 85
10 3 17
3 3
1 1 1
1 99 1
1 1 1
*/

#include <iostream>

using namespace std;

int k, m, n;
int grid[10][10];    // 开大一点，之后处理的时候采用1-index,不用处理边界了
bool visited[10][10]; // 注意只用查找上方和左边四个方向即可，减枝一半

int ans = 0;

void dfs(int x, int y, int sum)
{
    if (x == n + 1 && y == 1)
    {
        ans = max(ans, sum);
        return;
    }

    int nx = y == m ? x + 1 : x;
    int ny = y == m ? 1 : y + 1;

    // 不选当前这个
    dfs(nx, ny, sum);
    // 选当前这个
    if (!(visited[x - 1][y - 1] == 1 || visited[x - 1][y] == 1 || visited[x][y - 1] == 1 || visited[x - 1][y + 1] == 1))
    {
        visited[x][y] = 1;
        dfs(nx, ny, sum + grid[x][y]);
        visited[x][y] = 0;
    }
}

int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int s = 0; s < 10; s++)
                visited[j][s] = 0;
        }
        cin >> n >> m;
        for (int j = 1; j <= n; j++)
        {
            for (int s = 1; s <= m; s++)
            {
                cin >> grid[j][s];
            }
        }
        dfs(1, 1, 0);
        cout << ans << "\n";
        ans = 0;
    }

    return 0;
}