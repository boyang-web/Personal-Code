/*例如：8-(3+2*6)/5+4 可以写为：8 3 2 6 * + 5 / - 4 +

其计算步骤为：

8 3 2 6 * + 5 / - 4 +
8 3 12 + 5 / - 4 +
8 15 5 / - 4 +
8 3 - 4 +
5 4 +
9

注意乘方运算 ^ 是从右向左结合的，即 2 ^ 2 ^ 3 为 2 ^ (2 ^ 3)，后缀表达式为 2 2 3 ^ ^。

其他同优先级的运算是从左向右结合的，
即 4 / 2 / 2 * 2 为 ((4 / 2) / 2) * 2，后缀表达式为 4 2 / 2 / 2 *。
编写一个程序，完成这个转换，要求输出的每一个数据间都留一个空格。*/

// 原始表达式没有负数但中间过程可能有负数
// 由于存在乘方，数字会很大，用long long
// #include <vector>
// #include <iostream>
// #include <string>
// #include <stack>
// #include <cmath>
// using namespace std;

// vector<string> postfix()
// {
//     stack<char> opstk;

//     vector<string> ans;
//     string input;
//     cin >> input;
//     for (char c : input)
//     {
//         if (isdigit(c))
//             ans.push_back(string(1, c));
//         else if (c == '(')
//             opstk.push(c);
//         else if (c == ')' || c == '+' || c == '-')
//         {
//             while (!opstk.empty() && opstk.top() != '(')
//             {
//                 ans.push_back(string(1, opstk.top()));
//                 opstk.pop();
//             }
//             if (c == ')')
//                 opstk.pop();
//             else
//                 opstk.push(c);
//         }
//         else if (c == '*' || c == '/')
//         {
//             while (!opstk.empty() && (opstk.top() == '*' || opstk.top() == '/' || opstk.top() == '^'))
//             {
//                 ans.push_back(string(1, opstk.top()));
//                 opstk.pop();
//             }
//             opstk.push(c);
//         }
//         else // 这里是^
//             opstk.push(c);
//     }
//     while (!opstk.empty())
//     {
//         ans.push_back(string(1, opstk.top()));
//         opstk.pop();
//     }
//     return ans;
// }

// string calc(string n1c, string n2c, string op)
// {
//     long long n1 = stoll(n1c);
//     long long n2 = stoll(n2c);
//     if (op == "+")
//         return to_string(n1 + n2);
//     if (op == "-")
//         return to_string(n1 - n2);
//     if (op == "*")
//         return to_string(n1 * n2);
//     if (op == "/")
//         return to_string(n1 / n2);
//     if (op == "^")
//         return to_string(pow(n1, n2));//这里不建议用pow，数字大了容易出现误差，会炸
//     return "";
// }

// void printstr(vector<string> str)
// {
//     for (auto token : str)
//         cout << token << " ";
//     cout << "\n";
// }

// int main()
// {
//     vector<string> post = postfix();
//     printstr(post);
//     while (post.size() > 1)
//         for (int i = 0; i < post.size(); i++)
//         {
//             if (post[i] == "+" || post[i] == "-" || post[i] == "*" || post[i] == "/" || post[i] == "^")
//             {
//                 string temp = calc(post[i - 2], post[i - 1], post[i]);
//                 post.erase(post.begin() + i - 2, post.begin() + i + 1);
//                 post.insert(post.begin() + i - 2, temp);
//                 printstr(post);
//                 break;
//             }
//         }

//     return 0;
// }

#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

vector<string> postfix()
{
    stack<char> opstk;
    vector<string> ans;
    string input;
    cin >> input;

    for (char c : input)
    {
        if (isdigit(c))
            ans.push_back(string(1, c));
        else if (c == '(')
            opstk.push(c);
        else if (c == ')' || c == '+' || c == '-')
        {
            while (!opstk.empty() && opstk.top() != '(')
            {
                ans.push_back(string(1, opstk.top()));
                opstk.pop();
            }
            if (c == ')')
                opstk.pop();
            else
                opstk.push(c);
        }
        else if (c == '*' || c == '/')
        {
            while (!opstk.empty() && (opstk.top() == '*' || opstk.top() == '/' || opstk.top() == '^'))
            {
                ans.push_back(string(1, opstk.top()));
                opstk.pop();
            }
            opstk.push(c);
        }
        else // ^
        {
            opstk.push(c); // ^ 右结合，不弹同级
        }
    }

    while (!opstk.empty())
    {
        ans.push_back(string(1, opstk.top()));
        opstk.pop();
    }

    return ans;
}

long long qpow(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

string calc(string n1c, string n2c, string op)
{
    long long n1 = stoll(n1c);
    long long n2 = stoll(n2c);

    if (op == "+")
        return to_string(n1 + n2);
    if (op == "-")
        return to_string(n1 - n2);
    if (op == "*")
        return to_string(n1 * n2);
    if (op == "/")
        return to_string(n1 / n2);
    if (op == "^")
        return to_string(qpow(n1, n2));

    return "";
}

void printstr(const vector<string> &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (i)
            cout << " ";
        cout << str[i];
    }
    cout << "\n";
}

bool isOp(const string &s)
{
    return s == "+" || s == "-" || s == "*" || s == "/" || s == "^";
}

int main()
{
    vector<string> post = postfix();
    printstr(post);

    while (post.size() > 1)
    {
        for (int i = 0; i < post.size(); i++)
        {
            if (isOp(post[i]))
            {
                string temp = calc(post[i - 2], post[i - 1], post[i]);
                post.erase(post.begin() + i - 2, post.begin() + i + 1);
                post.insert(post.begin() + i - 2, temp);
                printstr(post);
                break;
            }
        }
    }

    return 0;
}