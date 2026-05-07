// 写个全排列。

#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

int visited[100];
vector<int> input;
vector<int> res;
int sz;

void dfs(int k)
{
    if (k == sz + 1)
    {
        for (int x : res)
            cout << x << " ";
        cout << "\n";
        return ;
    }
    for(int i=0;i<sz;i++)
    {
        if(visited[i]==0)
        {
        visited[i]=1;
        res.push_back(input[i]);
        dfs(k+1);
        res.pop_back();
        visited[i]=0;
        }
    }
    
}

int main()
{
    ifstream fin("in.txt");
    int num;
    while (fin >> num)
        input.push_back(num);

    sz = input.size();
    dfs(1);
    return 0;
}