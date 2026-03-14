/*
要点：根据数据规模分析暴力枚举的可行性
2≤N≤1000
125mb
1s

一秒钟可以运行10^8次左右
这里次数大约是10次*1000^2/2大约是10^6量级 微秒级别
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int chinese[1001], math[1001], english[1001], totol[1001];
    int count = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> chinese[i] >> math[i] >> english[i];
        totol[i] = chinese[i] + math[i] + english[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool chinese_right = abs(chinese[i] - chinese[j]) <= 5;
            bool math_right = abs(math[i] - math[j]) <= 5;
            bool english_right = abs(english[i] - english[j]) <= 5;
            bool totol_right=abs(totol[i] - totol[j]) <= 10;
            if(chinese_right&&math_right&&english_right&&totol_right)
            count++;
        }
    }
    cout<<count;
    return 0;
}
