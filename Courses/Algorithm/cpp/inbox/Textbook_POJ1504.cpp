// 求两个数逆转过来的和，注意前导零会被忽略，如1500->51
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// 第一个比较蠢的版本
void version1()
{
    string n1, n2;
    cin >> n1 >> n2;
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    bool isfirstnonzero = 0;
    while (!isfirstnonzero && n1.size() > 1)
    {
        auto it = n1.begin();
        if (*it != '0')
        {
            isfirstnonzero = !isfirstnonzero;
            continue;
        }
        n1.erase(it);
    }
    isfirstnonzero = 0;
    while (!isfirstnonzero && n2.size() > 1)
    {
        auto it = n2.begin();
        if (*it != '0')
        {
            isfirstnonzero = !isfirstnonzero;
            continue;
        }
        n2.erase(it);
    }
    cout << stoi(n1) + stoi(n2);
}

// 实则不用搞这么复杂
void version2()
{
    string n1, n2;
    cin >> n1 >> n2;
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    while (n1.size() > 1 && n1[0] == '0')
        n1.erase(n1.begin());
    while (n2.size() > 1 && n2[0] == '0')
        n2.erase(n2.begin());
    cout << stoi(n1) + stoi(n2);
}

//更好的写法应该是裁切子串、拆分函数
int revNum(string str)
{
    reverse(str.begin(),str.end());
    int pos=0;
    while(str[pos]=='0'&&pos<str.size()-1)//不走到最后一个字符，防止"0"这种极端输入
    pos++;
    return stoi(str.substr(pos));//从当前开始直接裁到尾
}

void version3()
{
    string n1,n2;
    cin>>n1>>n2;
    cout<<revNum(n1)+revNum(n2);
}

int main()
{

    return 0;
}