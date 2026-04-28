// #include <iostream>

// using namespace std;

// // 假设给定数据长宽小于等于1000

// int grid[1002][1002];
// bool visited[1002][1002];
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};

// int n, m;

// void dfs(int x, int y)
// {
//     visited[x][y] = true;
//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + dx[i];
//         int ny = x + dy[i];
//         if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && visited[nx][ny] == false && grid[nx][ny] == 0)
//         {
//             dfs(nx, ny);
//             grid[nx][ny] = 1;
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             cin >> grid[i][j];

//     for (int i = 1; i <= n; i++)
//     {
//         if (grid[i][1] == 0)
//             dfs(i, 1);
//         if (grid[i][m] == 0)
//             dfs(i, m);
//     }
//     for (int j = 1; j <= m; j++)
//     {
//         if (grid[1][j]==0)
//             dfs(1, j);
//         if (grid[n][j]==0)
//             dfs(n, j);
//     }

//     int cnt = 0;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             if (grid[i][j] == 0)
//                 cnt++;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// // 假设n小于25,要求是输入前三个合法解和总解数量
// int n;
// vector<int> ans;
// int ans_num;
// bool col[30];
// bool diag1[60];
// bool diag2[60];

// int times = 3;
// void dfs(int x) // 处理到第x行
// {
//     if (x == n + 1)
//     {
//         ans_num++;
//         if (times > 0)
//         {
//             for (int x : ans)
//                 cout << x << " ";
//             cout << "\n";
//             times--;
//         }
//         return;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (!col[i] && !diag1[n + x - i] && !diag2[x + i])
//         {
//             ans.push_back(i);
//             col[i] = 1;
//             diag1[n + x - i] = 1;
//             diag2[x + i] = 1;
//             dfs(x + 1);
//             col[i] = 0;
//             diag1[n + x - i] = 0;
//             diag2[x + i] = 0;
//             ans.pop_back();
//         }
//     }
// }

// int main()
// {
//     cin >> n;
//     dfs(1);
//     cout << ans_num;
//     return 0;
// }

//矩阵取数，要求上下左右不相邻，求最大和
#include <iostream>
#include <vector>
using namespace std;
// 先假定数据小于100*100
int n, m;
int grid[102][102]; // 1-based
bool visited[102][102];

int ans = 0;

void dfs(int x, int y, int sum)
{
    
    if (x == n + 1 && y == 1)
    {
        ans = max(ans, sum);
        return;
    }
    int nx = y == m ? x + 1 : x;
    int ny = y == m ? 1: y+1;

    dfs(nx, ny, sum);
    if (!visited[x][y - 1] && !visited[x - 1][y]) // 合法
    {
        visited[nx][ny] = true;
        dfs(nx, ny, sum + grid[x][y]);
        visited[nx][ny] = false;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    dfs(1, 1, 0);
    cout << ans;
    return 0;
}
