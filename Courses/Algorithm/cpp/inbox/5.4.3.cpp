#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
/*
global:targetx,targety,dx,dy,grid,visited
state: boxx,boxy,manx,many,cnt;
is_man_get(man->need):needx=x-dx nx=x+dx
if is_man_get and in_grid ->bfs

推完更新状态
*/
// struct state
// {
//     int boxx;
//     int boxy;
//     int manx;
//     int many;
//     int cnt = 0;
//     state(int bx, int by, int mx, int my, int c) : boxx(bx), boxy(by), manx(mx), many(my), cnt(c) {}
//     state() {}
// };
// int targetx, targety;
// int n, m;
// int grid[10][10];
// int box_visited[10][10];
// int visited[10][10];
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};

// void clear_visited()
// {
//     for(int i=0;i<10;i++)
//     {
//         for(int j=0;j<10;j++)
//         {
//             visited[i][j]=false;
//         }
//     }
// }
// bool is_valid(int x, int y)
// {
//     return x > 0 && y > 0 && x <=n && y <=m && grid[x][y] == 0;
// }
// bool is_man_get(int x, int y, int tx, int ty)
// {
//     clear_visited();
//     if (x == tx && y == ty)
//         return true;
//     queue<pair<int, int>> q;
//     q.push({x, y});
//     visited[x][y]=true;
//     while (!q.empty())
//     {
//         pair<int, int> cur = q.front();
//         q.pop();
//         visited[cur.first][cur.second]=true;
//         if (cur.first == tx && cur.second == ty)
//             return true;
//         for (int i = 0; i < 4; i++)
//         {
//             int nx = cur.first + dx[i];
//             int ny = cur.second + dy[i];
//             if (is_valid(nx, ny)&&visited[nx][ny]==false)
//             {
//                 q.push({nx, ny});
//             }
//         }
//     }
//     return false;
// }
// int main()
// {
//     ifstream fin("in.txt");
//     fin >> n >> m;
//     state init;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             int temp;
//             fin >> temp;
//             if (temp == 1)
//                 grid[i][j] = 1;
//             if (temp == 2)
//             {
//                 init.boxx = i;
//                 init.boxy = j;
//             }
//             if (temp == 3)
//             {
//                 targetx = i;
//                 targety = j;
//             }
//             if (temp == 4)
//             {
//                 init.manx = i;
//                 init.many = j;
//             }
//         }
//     }
//     queue<state> q;
//     q.push(init);
//     box_visited[init.boxx][init.boxy]=true;
//     while (!q.empty())
//     {
//         state cur = q.front();
//         q.pop();
//         box_visited[cur.boxx][cur.boxy]=true;
//         if (cur.boxx == targetx && cur.boxy == targety)
//         {
//             cout << cur.cnt;
//             return 0;
//         }
//         for (int i = 0; i < 4; i++)
//         {
//             int nx = cur.boxx + dx[i];
//             int ny = cur.boxy + dy[i];
//             int needx = cur.boxx - dx[i];
//             int needy = cur.boxy - dy[i];
//             if (is_valid(nx, ny) && is_man_get(cur.manx, cur.many, needx, needy)&&box_visited[nx][ny]==false)
//             {
//                 state nstate(nx, ny, cur.boxx, cur.boxy, cur.cnt + 1);
//                 q.push(nstate);
//             }
//         }
//     }

//     return 0;
// }

#include <queue>
#include <iostream>
#include<fstream>
using namespace std;

struct state
{
    int boxx;
    int boxy;
    int manx;
    int many;
    int cnt = 0;

    state(int bx, int by, int mx, int my, int c)
        : boxx(bx), boxy(by), manx(mx), many(my), cnt(c) {}

    state() {}
};

int targetx, targety;
int n, m;
int grid[10][10];

bool box_visited[10][10][10][10];
bool visited[10][10];             
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void clear_visited()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            visited[i][j] = false;
        }
    }
}

bool is_valid(int x, int y)
{
    return x >= 1 && x <= n &&y >= 1 && y <= m &&grid[x][y] != 1;
}

bool is_man_get(int x, int y, int tx, int ty, int boxx, int boxy)
{
    if (!is_valid(tx, ty))
        return false;

    clear_visited();

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == tx && cur.second == ty)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (!is_valid(nx, ny))
                continue;

            if (nx == boxx && ny == boxy)
                continue;

            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return false;
}

int main()
{
    ifstream fin("in.txt");
    fin >> n >> m;

    state init;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int temp;
            fin >> temp;

            if (temp == 1)
            {
                grid[i][j] = 1;
            }
            else if (temp == 2)
            {
                init.boxx = i;
                init.boxy = j;
                grid[i][j] = 0;
            }
            else if (temp == 3)
            {
                targetx = i;
                targety = j;
                grid[i][j] = 0;
            }
            else if (temp == 4)
            {
                init.manx = i;
                init.many = j;
                grid[i][j] = 0;
            }
            else
            {
                grid[i][j] = 0;
            }
        }
    }

    init.cnt = 0;

    queue<state> q;
    q.push(init);

    box_visited[init.boxx][init.boxy][init.manx][init.many] = true;

    while (!q.empty())
    {
        state cur = q.front();
        q.pop();

        if (cur.boxx == targetx && cur.boxy == targety)
        {
            cout << cur.cnt;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.boxx + dx[i];
            int ny = cur.boxy + dy[i];

            int needx = cur.boxx - dx[i];
            int needy = cur.boxy - dy[i];

            if (!is_valid(nx, ny))
                continue;

            if (!is_valid(needx, needy))
                continue;

            if (!is_man_get(cur.manx, cur.many, needx, needy, cur.boxx, cur.boxy))
                continue;

            state nstate(nx, ny, cur.boxx, cur.boxy, cur.cnt + 1);

            if (!box_visited[nstate.boxx][nstate.boxy][nstate.manx][nstate.many])
            {
                box_visited[nstate.boxx][nstate.boxy][nstate.manx][nstate.many] = true;
                q.push(nstate);
            }
        }
    }

    cout << -1;
    return 0;
}