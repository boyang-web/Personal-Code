/*
给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。

请你计算该表达式。返回一个表示表达式值的整数。

注意：

有效的算符为 '+'、'-'、'*' 和 '/' 。
每个操作数（运算对象）都可以是一个整数或者另一个表达式。
两个整数之间的除法总是 向零截断 。
表达式中不含除零运算。
输入是一个根据逆波兰表示法表示的算术表达式。
答案及所有中间计算结果可以用 32 位 整数表示。


示例 1：

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
*/

#include <vector>
#include <string>
#include <stack>

using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        int n1, n2;
        for (string c : tokens)
        {
            if (stk.size() > 1&&(c=="+"||c=="-"||c=="*"||c=="/"))//这里的顺序不对，需要把判断数字的逻辑前移
            {
                n2 = stk.top();
                stk.pop();
                n1 = stk.top();
                stk.pop();
            }

            if (c == "+")
            {
                stk.push(n1 + n2);
            }
            else if (c == "-")
            {
                stk.push(n1 - n2);
            }
            else if (c == "*")
            {
                stk.push(n1 * n2);
            }
            else if (c == "/")
            {
                stk.push(n1 / n2);
            }
            else
            {
                stk.push(stoi(c));
            }
        }
        return stk.top();
    }
};