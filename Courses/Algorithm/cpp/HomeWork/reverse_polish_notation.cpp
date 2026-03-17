/*
【问题描述】
根据逆波兰表示法，求表达式的值。有效的运算符包括+，-，*，/。每个运算对象可以是整数，
也可以是另一个逆波兰表达式。
假设给定逆波兰表达式总是有效的，
换句话说，表达式总会得出有效数值且不存在除数为0的情况。其中整数除法只保留整数部分。
【输入形式】
     每个样例是一行，为有效的表达式，每个数字和运算符号之间用“,”隔开
【输出形式】
     表达式的计算结果
【样例输入】
      2,1,+,3,*
【样例输出】
     9
【样例说明】
    测试数据的文件名为in.txt
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>
#include <vector>
using namespace std;



#include <cctype>
int main()
{
    stack<int> nums;
    ifstream fin("in.txt");
    string token;
    while (getline(fin, token, ','))
    {//这里需要考虑负数
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
            nums.push(stoi(token));
        else
        {
            int n2 = nums.top();
            nums.pop();
            int n1 = nums.top();
            nums.pop();
            if (token == "+")
                nums.push(n1 + n2);
            if (token == "-")
                nums.push(n1 - n2);
            if (token == "*")
                nums.push(n1 * n2);
            if (token == "/")
                nums.push(n1 / n2);
        }
    }
    if(!nums.empty())
    cout << nums.top();
    else
    cout<<"0";//最后一个案例还来个空
    return 0;
}


