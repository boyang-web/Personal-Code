//寻找岛屿。核心思维是打开思路，把dfs当作一个染色工具，吃掉当前岛屿的所有地块,
//1是岛 0是海
//打印岛屿数量

#include<iostream>
using namespace std;

//全局变量
int m,n;
char grid[10][10];
bool visited[10][10]={false};

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int cnt=0;

void dfs(int x,int y)
{
    visited[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&ny>=0&&nx<m&&ny<n&&!visited[nx][ny]&&grid[nx][ny]=='1')
        {
            dfs(nx,ny);
        }
    }
}

int main()
{
//输入
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];

        }
    }

//每个点进行dfs
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        if(grid[i][j]=='1'&&!visited[i][j])
        {
        cnt++;
        dfs(i,j);
        }
    }
}

cout<<cnt;
return 0;
}
