// 输入字符矩阵，S E 代表开始和结束 #墙 .路
// 先输入mn代表边界，返回整个路径走法，m,n小于5

// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;
// // 全局变量
// bool visited[6][6] = {true};
// char maze[6][6];
// int m, n;
// stack<vector<int>> solution;

// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};

// int sx, sy;

// void dfs(int x, int y)
// {
//     solution.push({x, y});
//     visited[x][y] == false;
//     // 终止状态
//     if (maze[x][y] == 'E')
//     {
//         while (!solution.empty())
//         {
//             cout << solution.top()[0] << solution.top()[0] << endl;
//             solution.pop();
//         }
//         return;
//     }
//     // 上下左右逻辑
//     for (int i = 0; i < 4; i++)
//     {
//         if(x>=0&&y>=0&&x<m&&x<n&&visited[x][y]&&maze[x][y]!='#')
//         {
//             int nx=x+dx[i];
//             int ny=y+dy[i];
//             dfs(nx,ny);
//         }
//     }
//     // 状态回溯
//     visited[x][y] = true;
//     return;
// }

// int main()
// {
//     // 输入部分
    
//     cin >> m >> n;
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> maze[i][j];
//             if (maze[i][j] == 'S')
//             {
//                 sx = i;
//                 sy = j;
//             }
//         }
//     }

//     // dfs部分
//     dfs(sx, sy);

//     return 0;
// }

//修改后版本
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool visited[6][6] = {false};//visited代表的是访问了没，true代表已访问
char maze[6][6];
int m, n;
stack<pair<int, int>> solution;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int sx, sy;
bool found = false;//found机制可以实现找到后结束查找的功能

void print_path()
{
    vector<pair<int, int>> temp;
    while (!solution.empty())
    {
        temp.push_back(solution.top());
        solution.pop();
    }

    for (int i = temp.size() - 1; i >= 0; i--)//倒序遍历，不然是倒着打印的
    {
        cout << temp[i].first << ' ' << temp[i].second << endl;
    }
}

void dfs(int x, int y)
{
    if (found) return;//这才是真正的截止条件

    visited[x][y] = true;
    solution.push({x, y});

    if (maze[x][y] == 'E')
    {
        found = true;
        print_path();
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];//先生成nx,ny再判定可行性
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            maze[nx][ny] != '#' && !visited[nx][ny])
        {
            dfs(nx, ny);
            if (found) return;//截断后面的回溯
        }
    }

    solution.pop();  // 当前点不在正确路径上，回溯撤销
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }

    dfs(sx, sy);

    if (!found)
    {
        cout << "No path found" << endl;
    }

    return 0;
}

//总结：大部分正确，但是对dfs截止条件和visited没有彻底认识，
//判断是否出界也没有做好，需要倒序答应也没有认知