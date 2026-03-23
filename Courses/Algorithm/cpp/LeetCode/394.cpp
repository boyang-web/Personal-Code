/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

测试用例保证输出的长度不会超过 105。

示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：

输入：s = "3[a2[c]]"
输出："accaccacc"
示例 3：

输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"
示例 4：

输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"

*/
//我的天，虽然是做过的，但是首次一次过！ 士气+1
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> nstk;
        stack<string> sstk;

        int curn = 0;
        string curs = "";

        for (char c : s)
        {
            if (isdigit(c))
                curn = curn * 10 + c - '0';
            else if (c == '[')
            {
                nstk.push(curn);
                sstk.push(curs);
                curn=0;
                curs="";
            }
            else if (c == ']')
            {
                int times=nstk.top();
                nstk.pop();
                string pres=sstk.top();
                sstk.pop();
                string temp="";
                for(int i=0;i<times;i++)
                {
                    temp+=curs;
                }
                curs=pres+temp;
            }
            else
            {
                curs+=c;
            }
        }
        return curs;
    }
};