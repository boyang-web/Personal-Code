#include <iostream>
#include <string>
#include <queue>
// 1-8行a-h列
using namespace std;

int steps = 0;
bool visited[9][9];

int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

struct node
{
    int x;
    int y;
    int step;
};

int bfs(int x, int y, int tox, int toy)
{
    queue<node> q;
    q.push({x, y, 0});
    while (!q.empty())
    {
        node cur = q.front();
        visited[cur.x][cur.y] = true;
        q.pop();
        if (cur.x == tox && cur.y == toy)
        {
            return cur.step;
        }
        for (int i = 0; i < 8; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && visited[nx][ny] == false)
            {
               
                q.push({nx, ny, cur.step+1});
            }
             
        }
    }
    return 0;
}

int main()
{
    string input;
    getline(cin, input);
    int x = input[0] - 'a' + 1;
    int y = input[1] - '0';
    int tox = input[3] - 'a' + 1;
    int toy = input[4] - '0';
    cout << bfs(x, y, tox, toy);
    return 0;
}
