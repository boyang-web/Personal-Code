/*1. P2058 海港
题目描述
小 K 是一个海港的海关工作人员，每天都有许多船只到达海港，船上通常有很多来自不同国家的乘客。

小 K 对这些到达海港的船只非常感兴趣，他按照时间记录下了到达海港的每一艘船只情况；
对于第 i 艘到达的船，他记录了这艘船到达的时间 t
  i(单位：秒)，船上的乘客数 k
 i，以及每名乘客的国籍 x

 i1,x

 i2,…,x

 ik。

小K统计了 n 艘船的信息，希望你帮忙计算出以每一艘船到达时间为止的 24 小时
（24 小时 =86400 秒）内所有乘船到达的乘客来自多少个不同的国家。

形式化地讲，你需要计算 n 条信息。对于输出的第 i 条信息，你需要统计满足 t

 i−86400<t
 p≤t
 i的船只 p，在所有的 x
 pj 中，总共有多少个不同的数。
输入格式
第一行输入一个正整数 n，表示小 K 统计了 n 艘船的信息。

接下来 n 行，每行描述一艘船的信息：前两个整数 t

  i和 k

 i 分别表示这艘船到达海港的时间和船上的乘客数量，接下来 k

 i 个整数 x

  ij表示船上乘客的国籍。

保证输入的 t

  i是递增的，单位是秒；表示从小K第一次上班开始计时，这艘船在第 t

  i秒到达海港。



输出格式
输出 n 行，第 i 行输出一个整数表示第 i 艘船到达后的统计信息。

输入输出样例
输入 #1复制

3
1 4 4 1 2 2
2 2 2 3
10 1 3*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
    queue<pair<int, vector<int>>> q;
    int n;
    map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k1, k2;
        cin >> k1 >> k2;
        vector<int> nation;
        for (int i = 0; i < k2; i++)
        {
            int temp;
            cin >> temp;
            nation.push_back(temp);
            mp[temp]++;
        }
        q.push({k1, nation});
        while (q.front().first < k1 - 86400)
        {
            for (int x : q.front().second)
            {
                if (mp[x] == 1)
                    mp.erase(x);
                else
                    mp[x]--;
            }
            q.pop();
        }
        cout<<mp.size()<<" ";
    }

    return 0;
}