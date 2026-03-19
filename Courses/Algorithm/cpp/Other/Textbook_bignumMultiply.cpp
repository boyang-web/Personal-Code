// 再次重写大数乘法
//评价：错误比我想象中的少
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// 实现两数相加函数和个位数乘数函数
//自己写的部分
// using namespace std;

// vector<int> addnum(vector<int> num1, vector<int> num2)
// {
//     vector<int> res;
//     int n1 = num1.size();
//     int n2 = num2.size();
//     int carry = 0;
//     for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0; i--, j--)
//     {
//         int p1 = (i >= 0) ? num1[i] : 0;
//         int p2 = (j >= 0) ? num2[j] : 0;
//         int sum = p1 + p2 + carry;
//         res.push_back(sum % 10);
//         carry = sum / 10;
//     }
//     if (carry != 0)
//         res.push_back(carry);
//     reverse(res.begin(), res.end());

//     return res;
// }

// vector<int> mulnum(int x, vector<int> num)
// {
//     int carry = 0;
//     int n = num.size();
//     vector<int> res;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         int sum = carry + x * num[i];
//         carry = sum / 10;
//         res.push_back(sum % 10);
//     }
//     if (carry != 0)
//         res.push_back(carry);
//     reverse(res.begin(), res.end());
//     return res;
// }
// using namespace std;

// vector<int> stov(string s)
// {
//     vector<int> res;
//     for (int i = 0; i < s.size(); i++)
//         res.push_back(s[i]-'0');//char转int的手法别忘了
//     return res;
// }

// int main()
// {
//     string s1, s2;
//     cin >> s1 >> s2;
//     vector<int> n1=stov(s1), n2=stov(s2);

//     vector<int> res={0};

//     for(int i=n2.size()-1;i>=0;i--)
//     {
//         vector<int> temp=mulnum(n2[i],n1);
//         res.push_back(0);
//         res=addnum(res,temp);
//     }

//     for(auto &x:res)
//     cout<<x;
//     return 0;
// }

//ai写的部分
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addnum(vector<int> num1, vector<int> num2)
{
    vector<int> res;
    int carry = 0;

    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; i--, j--)
    {
        int p1 = (i >= 0) ? num1[i] : 0;
        int p2 = (j >= 0) ? num2[j] : 0;
        int sum = p1 + p2 + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
    }

    if (carry)
        res.push_back(carry);

    reverse(res.begin(), res.end());
    return res;
}

vector<int> mulnum(int x, vector<int> num)
{
    vector<int> res;
    int carry = 0;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        int sum = x * num[i] + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
    }

    while (carry)
    {
        res.push_back(carry % 10);//这里改的有点多余
        carry /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

vector<int> stov(string s)
{
    vector<int> res;
    for (char c : s)
        res.push_back(c - '0');
    return res;
}

void trimLeadingZero(vector<int> &num)//还有前导零的处理，这个也不是必须的
{
    while (num.size() > 1 && num[0] == 0)
        num.erase(num.begin());
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> n1 = stov(s1);
    vector<int> n2 = stov(s2);

    vector<int> res = {0};

    for (int i = n2.size() - 1; i >= 0; i--)//我写错了，倒序遍历其实就是从个位开始
    {
        vector<int> temp = mulnum(n2[i], n1);

        int zeros = n2.size() - 1 - i;
        while (zeros--)
            temp.push_back(0);

        res = addnum(res, temp);
    }

    trimLeadingZero(res);

    for (int x : res)
        cout << x;

    return 0;
}