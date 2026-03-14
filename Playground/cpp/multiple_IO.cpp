//测试一下洛谷的输入模式
#include <iostream>
#include <vector>

using namespace std;

void test1()
{
    int n;
    cin >> n;
    vector<vector<int>> data(n,vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin>>data[i][0]>>data[i][1]>>data[i][2];
    }
    for(vector<int> v :data)
    {
        for(int n : v)
        cout<<n<<" ";
        cout<<endl;
    }
}

int main()
{
    test1();
    return 0;
}