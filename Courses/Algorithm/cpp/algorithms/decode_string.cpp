/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。

1. 输入字符串总是有效的, k 保证为正整数,不考虑输入字符串非法情况。

2. 输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

3. 所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

【输入形式】

一行字符串s

【输出形式】

解码后的字符串

【样例输入1】

3[a]2[bc]

【样例输出1】

aaabcbc

【样例输入2】

3[a2[c]]

【样例输出2】

accaccacc

【样例输入3】

2[abc]3[cd]ef

【样例输出3】

abcabccdcdcdef

【样例输入4】

abc3[cd]xyz

【样例输出4】

abccdcdcdxyz*/

// #include <stack>
// #include <iostream>
// #include <string>

// using namespace std;
// 依旧自己写出一百万个错误
// int main()
// {
//     // 次数栈
//     stack<int> num;
//     // 字符串栈
//     stack<string> str;
//     string input;
//     string curs = ""; // 维护一个当前处理着的字符串
//     string curn = ""; // 当前处理着的数字
//     cin >> input;
//     for (char c : input)
//     {
//         if (isdigit(c))
//         {
//             if(curs!="")
//             {
//             str.push(curs);
//             curs="";
//             }

//             curn += c;
//         }
//         else if (c == '[')
//         {
//             num.push(stoi(curn));
//             curn = "";
//             str.push("[");
//         }
//         else if (c == ']')
//         {
//             //先去接上栈里[之前的字符，再抽取数字翻倍再入字符栈
//             while(str.top()!="[")
//             {
//                 curs=str.top()+curs;
//                 str.pop();
//             }
//             str.pop();
//             for(int i=0;i<num.top();i++)
//             curs+=curs;
//             num.pop();
//             str.push(curs);
//             curs="";
//         }
//         else//一般字符的时候
//         {
//             curs+=c;
//         }
//     }
//     cout<<str.top();
//     return 0;
// }

// 学会了思路再来一次
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    stack<int> numstk;
    stack<string> strstk;

    int curNum = 0;
    string curStr = "";

    string input;
    cin >> input;
    for (char c : input)
    {
        if (isdigit(c))
        {
            curNum = curNum * 10 + (c - '0');
        }
        else if (c == '[') // 存储curNum 和curStr
        {
            numstk.push(curNum);
            strstk.push(curStr);
            curNum = 0;
            curStr = "";
        }
        else if (c == ']') // 调用num和str,翻倍后成为curstr
        {
            int times=0;
            if(!numstk.empty())
            {
            times = numstk.top();
            numstk.pop();
            }

            string prestr="";
            if(!strstk.empty())
            {
            prestr = strstk.top();
            strstk.pop();
            }

            string temp = "";
            for (int i = 0; i < times; i++)
            {
                temp += curStr;
            }
            curStr = prestr + temp;
        }
        else
        {
            curStr += c;
        }
    }
    cout << curStr;
    return 0;
}