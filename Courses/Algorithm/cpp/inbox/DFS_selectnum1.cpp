//例题 1：一排数里取若干个，不能取相邻，求最大和

#include<vector>
#include<iostream>
using namespace std;

vector<int> v={1,2,3,6};
int ans=0;
void dfs(int i,int sum)//处理index，维护sum
{
    if(i>=v.size())
    {
        ans=max(ans,sum);
        return ;
    }
    //选i+1
    dfs(i+2,sum+v[i]);
    //不选
    dfs(i+1,sum);
}

int main()
{
    dfs(0,0);
    cout<<ans;
    return 0;
}