#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string midfix;
    cin >> midfix;
    stack<char> opstk;
    for (auto &x : midfix)
    {
        if (isdigit(x))
            cout << x << " ";
        if (x == '*' || x == '/')
        {
            while (!opstk.empty() && (opstk.top() == '*' || opstk.top() == '/'))
            {
                cout << opstk.top() << " ";
                opstk.pop();
            }
            opstk.push(x);
        }
        if (x == '+' || x == '-')
        {
            while (!opstk.empty() && opstk.top() != '(')
            {
                cout << opstk.top() << " ";
                opstk.pop();
            }
            opstk.push(x);
        }
        if (x == '(')
            opstk.push(x);
        if (x == ')')
        {
            while (opstk.top() != '(' && !opstk.empty())
            {
                cout << opstk.top() << " ";
                opstk.pop();
            }
            opstk.pop();
        }
    }
    while (!opstk.empty())
    {
        cout << opstk.top() << " ";
        opstk.pop();
    }
    return 0;
}