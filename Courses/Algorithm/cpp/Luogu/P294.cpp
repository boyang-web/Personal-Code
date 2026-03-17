/*
题目描述
鳌头山上有 n 个观景点，观景点两两之间有游步道共 m 条。
高手的那个它，不喜欢太刺激的过程，因此那些没有路的观景点高手是不会选择去的。
另外，她也不喜欢去同一个观景点一次以上。而高手想让他们在一起的路程最长（观景时它不会理高手），已知高手的穿梭机可以让他们在任意一个观景点出发，也在任意一个观景点结束。

输入格式
第一行，两个用空格隔开的整数 n 、 m. 之后 m 行，为每条游步道的信息：两端观景点编号、长度。

输出格式
一个整数，表示他们最长相伴的路程。

4 6
1 2 10
2 3 20
3 4 30
4 1 40
1 3 50
2 4 60
*/

// 写一半卡住了，遂问ai
//  #include<iostream>
//  #include<algorithm>
//  #include<vector>
//  using namespace std;
//  //全局变量部分
//  //使用邻接表存储
//  int n,m;
//  vector<pair<int,int>> graph[60];
//  bool visited[60]={false};
//  int time=0;
//  int maxtime=0;

// void dfs(int island)
// {
//     visited[island]=true;

//     for(auto &x:graph[island])
//     {
//         dfs(x.first);
//         time+=x.second;
//     }

//     visited[island]=false;
// }

// int main()
// {
// //输入部分
// //由于是无向图，要正反都存；
// cin>>n>>m;
// for(int i=0;i<m;i++)
// {
//     int fi,si,va;
//     cin>>fi>>si>>va;
//     graph[fi].push_back({si,va});
//     graph[si].push_back({fi,va});
// }

// //dfs部分
// for(int i=0;i<n;i++)
// {
//     visited[n-1]=false;
//     visited[n]=true;
//     time=0;
//     dfs(i+1);
//     maxtime=max(time,maxtime);
// }
// cout<<maxtime;
//     return 0;
// }

// ai的版本
//  #include<iostream>
//  #include<algorithm>
//  #include<vector>
//  using namespace std;

// // 全局变量部分
// int n,m;
// vector<pair<int,int>> graph[60];
// bool visited[60]={false};
// int time1=0;
// int maxtime=0;

// void dfs(int island)
// {//注意每个节点都求一次最大路径
//     maxtime = max(maxtime, time1);   // 当前路径可以作为答案

//     for(auto &x : graph[island])
//     {
//         int nextIsland = x.first;
//         int roadLen = x.second;

//         if(!visited[nextIsland])//还是要探查是否走过
//         {
//             visited[nextIsland] = true;//双重回溯
//             time1 += roadLen;

//             dfs(nextIsland);

//             time1 -= roadLen;            // 回溯：撤销这条边
//             visited[nextIsland] = false; // 回溯：撤销访问标记
//         }
//     }
// }

// int main()
// {
//     // 输入部分
//     cin >> n >> m;
//     for(int i=0;i<m;i++)
//     {
//         int fi,si,va;
//         cin >> fi >> si >> va;
//         graph[fi].push_back({si,va});
//         graph[si].push_back({fi,va});
//     }

//     // dfs部分
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++) visited[j]=false;//清空重置

//         time1=0;
//         visited[i]=true;   // 以 i 为起点
//         dfs(i);
//     }

//     cout << maxtime;
//     return 0;
// }

// 自己再写一次

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
// 全局变量，邻接表存储图
vector<pair<int, int>> graph[100];
bool visited[100] = {false};
int len = 0;
int maxlen = 0;

int m, n;

void dfs(int island)
{
    
    maxlen=max(maxlen,len);
    for(auto &x:graph[island])
    {
        if(!visited[x.first])
        {
            visited[x.first]=true;
            len+=x.second;
            dfs(x.first);//这里也写错了
            len-=x.second;
            visited[x.first]=false;
        }

    }

    
}


int main()//。。拼写错了
{
    // 读取
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int fn, sn, value;
        cin>>fn>>sn>>value;//忘写了。
        graph[fn].push_back({sn,value});
        graph[sn].push_back({fn,value});
    }
    //dfs
    for(int i=1;i<=n;i++)//新错误：大部分编号都是从1开始的，所以稍有变化
    {
        memset(visited,false,sizeof(visited));
        len=0;
        visited[i]=true;
        dfs(i);
    }

    cout<<maxlen;

    return 0;
}
