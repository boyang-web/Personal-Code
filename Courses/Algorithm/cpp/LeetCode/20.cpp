/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。*/

//难得近乎一次过
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{' || stk.empty())
                stk.push(c);
            else if (c == ')')
            {
                if (stk.top() == '(')
                    stk.pop();
                else
                    stk.push(c);
            }
            else if (c == ']')
            {
                if (stk.top() == '[')
                    stk.pop();
                else
                    stk.push(c);
            }
            else if (c == '}')
            {
                if (stk.top() == '{')
                    stk.pop();
                else
                    stk.push(c);
            }
        }
        if (stk.empty())
            return true;
        return false;
    }
};