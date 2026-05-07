/*有了防护伞，并不能完全避免 2012 的灾难。地球防卫小队决定去求助外星种族的帮助。
经过很长时间的努力，小队终于收到了外星生命的回信。但是外星人发过来的却是一串密码。
只有解开密码，才能知道外星人给的准确回复。解开密码的第一道工序就是解压缩密码，
外星人对于连续的若干个相同的子串 X 会压缩为 [DX] 的形式（D 是一个整数且 1≤D≤99），
比如说字符串 CBCBCBCB 就压缩为 [4CB] 或者[2[2CB]]，
类似于后面这种压缩之后再压缩的称为二重压缩。如果是 [2[2[2CB]]]
则是三重的。现在我们给你外星人发送的密码，请你对其进行解压缩。

输入格式
输入一行，一个字符串，表示外星人发送的密码。

输出格式
输出一行，一个字符串，表示解压缩后的结果。

输入输出样例
输入 #1复制

AC[3FUN]
输出 #1复制
ACFUNFUNFUN
说明/提示*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<int> times;
    stack<string> strs;
    int curtime = 0;
    string curstr = "";

    string input;
    cin >> input;
    for (char c : input)
    {
        if (isdigit(c))
        {
            curtime = curtime * 10 + c - '0';
        }
        else if (c == '[')
        {
            if (curtime != 0)
                times.push(curtime);
            strs.push(curstr);
            curtime = 0;
            curstr = "";
        }
        else if (c == ']')
        {
            string prestr = strs.top();
            strs.pop();
            int time = times.top();
            times.pop();
            string temp = "";
            for (int i = 0; i < time; i++)
            {
                temp += curstr;
            }
            curstr = prestr + temp;
        }
        else
        {
            if (curtime != 0)
            {
                times.push(curtime);
                curtime = 0;
            }
            curstr += c;
        }
    }
    cout << curstr;
    return 0;
}