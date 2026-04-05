/*B 君站在一个 n×n 的棋盘上。最开始，B君站在 (1,1) 这个点，他要走到 (n,n) 这个点。
B 君每秒可以向上下左右的某个方向移动一格，但是很不妙，C 君打算阻止 B 君的计划。
每秒结束的时刻，C 君 会在 (x,y) 上摆一个路障。B 君不能走在路障上。
B 君拿到了 C 君准备在哪些点放置路障。所以现在你需要判断，B 君能否成功走到 (n,n)。
保证数据足够弱：也就是说，无需考虑“走到某处然后被一个路障砸死”的情况，因为答案不会出现此类情况。
输入格式
首先是一个正整数 T，表示数据组数。
对于每一组数据：
第一行，一个正整数 n。
接下来 2n−2 行，每行两个正整数 x 和 y，意义是在那一秒结束后，(x,y) 将被摆上路障。
输出格式
对于每一组数据，输出 Yes 或 No，回答 B 君能否走到 (n,n)。*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
// 全局变量


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
    int times;
    cin >> times;
    for (int i=0; i < times; i++)
    {
        queue<pair<int, int>> q;
        queue<pair<int, int>> obstacle;
        int n;
        bool find = false;
        cin >> n;
        // 读取障碍
        for (int i = 0; i < 2 * n - 2; i++)
        {
            int x, y;
            cin >> x >> y;
            obstacle.push({x, y});
        }
        // 初始化
        vector<vector<bool>> grid(n+1,vector<bool>(n+1,true));
        vector<vector<bool>> vis(n+1,vector<bool>(n+1,false));
        q.push({1, 1});
        vis[1][1]=true;
        while (!q.empty())
        {
            if (q.front().first == n && q.front().second == n)
            {
                cout << "Yes" << "\n";
                find = true;
                break;
            }
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> temp = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = temp.first + dx[i];
                    int ny = temp.second + dy[i];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && grid[nx][ny] &&!vis[nx][ny])
                    {
                        vis[nx][ny]=true;
                        q.push({nx, ny});
                    }
                }
            }
            if (!obstacle.empty())
            {
                grid[obstacle.front().first][obstacle.front().second] = false;
                obstacle.pop();
            }
        }
        if (find == false)
            cout << "No\n";
   
    }

    return 0;
}