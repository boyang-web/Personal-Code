/*
n*n的棋盘，输出前三个解和解的总数
*/
#include <vector>
#include <iostream>
using namespace std;

int n; // 棋盘
// 许可数组
bool col[20];   // 由于初始化默认是0，那就定义为是否被占用
bool diag1[30]; // 注意要给r-c加一个n偏移量，让其不出现负数
bool diag2[30];

vector<int> ans;

int ansn=0;      // 答案个数
int times = 3; // 顺应题目要求输出前三个

void dfs(int row)
{
    if (row == n + 1)
    {
        ansn++;
        if(times>=1)
        {
            for(int x:ans)
            cout<<x<<" ";
            cout<<"\n";
            times--;
        }
        return;
    }
    for (int i = 1; i <= n; i++) // 是一个八叉树遍历
    {
        if (!col[i] && !diag1[row-i+n] && !diag2[row+i]) // 减枝
        {
            ans.push_back(i);
            col[i] = true;
            diag1[row - i + n] = true;
            diag2[row + i] = true;
            dfs(row + 1);
            col[i] = false;
            diag1[row - i + n] = false;
            diag2[row + i] = false;
            ans.pop_back();
        }
    }
}

int main()
{
    cin >> n;
    dfs(1); // 在处理第几行；
    cout<<ansn;
    return 0;
}