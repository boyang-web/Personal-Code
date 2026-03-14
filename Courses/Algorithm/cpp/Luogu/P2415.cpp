/*
输出集合所有子集的和元素和的和
集合元素小于等于30

要点：
1.利用while(cin>>array[i++]);连续输入直到EOF
    注意这里最后一次判断依旧进行了i++,也就是说数组长度n=i-1
2.感知到是一个大数了先long long 起手
3.<cmath>pow的使用
4.
*/
#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int set[31];
    int i = 0;
    while (cin >> set[i++])
        ;
    long long sum = 0;
    int n=i-1;
    for (int j = 0; j < n; j++)
    {
        sum+=set[j]*pow(2,n-1);
    }
    cout<<sum;
        return 0;
}
