/*数学老师需快速验证学生书写的算术表达式与标准答案是否等效，现要求编写C++程序，
通过计算表达式结果的方式实现判断逻辑。

【实验要求】

（1）输入规则：第一行输入正整数n（表示需判断的算术表达式对数/测试用例数，1≤n≤20）；

后续输入n对算术表达式，每对表达式各占一行（无空行），单个表达式长度不超过20个字符。

（2）表达式构成：包含运算符（ + 、-、*、/）、运算数（一位数字或单个大小写区别的字母） 、

输入表达式可能有语法错误，需要有效性验证。

（3）计算规则：除号“/”按整数除法规则计算（结果取整，例如5/3结果为1，分母为0表示表达式除0出错）；
必须通过逆波兰式（后缀表达式）完成表达式的计算逻辑。

【输入格式】in.txt文件输入n个测试用例

（1）第一行：正整数n（测试用例数量，1≤n≤20）。

（2）后续2n行：每2行对应1个测试用例，即每个测试用例包含两个算术表达式（各占一行）。

【输出格式】文件out.txt输出共n行，对应n个对表达式的判断结果：若第i对表达式计算结果等效，
第i行输出：TRUE”；否则输出“FALSE”。若第i对表达式的第j个表达式是无效表达式，第i行输出：
表达式j无效！若第i对表达式的第j个表达式除0错误，第i行输出：表达式j除0出错。

【样例输入】输入文件in.txt内容如下：

4

3*(a+2*3/(2+1))-b*(5-2)

(b+1)*(5-3)+3-(6-4)*c

6+5+4+3+2

4*(2+6/3)+2

(a+b)*(-b)

a*a-b*b

5-4+8/(7-6/2-9/2)

2*3-8

【样例输出】输出文件out.txt如下:

测试用例1：TRUE

测试用例2：FALSE

测试用例3：表达式1无效！

测试用例4：表达式1除0出错！

【评分标准】

5组测试用例，每通过一个测试用例得20分*/

/*两个表达式都要判断除0和无效，其次无效的判断用状态机比较好，*/
// #include <string>
// #include <sstream>
// #include <fstream>
// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;
// bool is_not_valid = 0;
// bool is_dev_zero = 0;
// // 状态管理
// bool is_operator(char c)
// {
//     return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
// }
// // 算结果，改错误
// int getres(string exp)
// {
//     is_not_valid = 0;
//     is_dev_zero = 0;
//     int res;

//     vector<char> postfix;
//     stack<char> opstk;
//     bool expect_op = is_operator(exp[0]);
//     // 改成后缀表达式，顺便判定valid
//     for (int i = 0; i < exp.size(); i++)
//     {
//         char c = exp[i];
//         if (is_operator(c) != expect_op)
//         {
//             is_not_valid = 1;
//             return -1;
//         }
//         if (is_operator(c))
//         { // 这里设置expect_op需要小心
//             if (c == '(')
//             {
//                 opstk.push(c);
//                 if (i < postfix.size() - 1)
//                     expect_op = is_operator(postfix[i + 1]);
//             }
//             if (c == ')')
//             {
//                 while (!opstk.empty() && opstk.top() != '(')
//                 {
//                     postfix.push_back(opstk.top());
//                     opstk.pop();
//                 }
//                 if (!opstk.empty()&&opstk.top()=='(')
//                     opstk.pop();
//                 expect_op = 1;
//             }
//             if (c == '+' || c == '-')
//             {
//                 while (!opstk.empty() && is_operator(c)&&c!='(')
//                 {
//                     postfix.push_back(opstk.top());
//                     opstk.pop();
//                 }
//                 expect_op=0;
//             }
//             if (c == '*' || c == '/')
//             {
//                 while(!opstk.empty()&&(c=='*'||c=='/'))
//                 {
//                     postfix.push_back(opstk.top());
//                     opstk.pop();
//                 }
//                 expect_op=0;
//             }
//         }
//         else
//         {
//             postfix.push_back(c);
//             expect_op = 1;
//         }
//         while(!opstk.empty())
//         {
//              postfix.push_back(opstk.top());
//                     opstk.pop();
//         }
//     }
//     // 计算已经合法的postfix,判定除零
//     stack<int> numstk;
//     for (char c : postfix)
//     {
//         if (is_operator(c))
//         {
//             int n2 = numstk.top();
//             numstk.pop();
//             int n1 = numstk.top();
//             numstk.pop();
//             if (c == '+')
//                 numstk.push(n1 + n2);
//             if (c == '-')
//                 numstk.push(n1 - n2);
//             if (c == '*')
//                 numstk.push(n1 * n2);
//             if (c == '/')
//             {
//                 if (n2 == 0)
//                 {
//                     is_dev_zero = 1;
//                     return -1;
//                 }
//                 numstk.push(n1 / n2);
//             }
//         }
//         else
//         {
//             numstk.push(c - '0');
//         }
//     }
//     res = numstk.top();
//     return res;
// }

// void process_pair_expression(ifstream &fin, int k)
// {
//     string exp1, exp2;
//     getline(fin, exp1);
//     getline(fin, exp2);

//     int res1 = getres(exp1);
//     bool exp1_not_valid = is_not_valid;
//     bool exp1_dev_zero = is_dev_zero;
//     int res2 = getres(exp2);
//     bool exp2_not_valid = is_not_valid;
//     bool exp2_dev_zero = is_dev_zero;

//     cout << "测试用例" << k << "：";
//     string ans = "";
//     if (exp1_not_valid)
//     {
//         ans += "表达式1无效！";
//     }
//     else if (exp1_dev_zero)
//     {
//         ans += "表达式1除0出错！";
//     }
//     if (exp2_not_valid)
//     {
//         ans += "表达式2无效！";
//     }
//     else if (exp2_not_valid)
//     {
//         ans += "表达式2除0出错！";
//     }
//     if (ans == "")
//     {
//         ans = res1 == res2 ? "TRUE" : "FALSE";
//     }
//     cout << ans << "\n";
// }

// int main()
// {
//     ifstream fin("in.txt");
//     ofstream fout("out.txt");
//     int n = 0;
//     fin >> n;
//     fin.ignore();
//     for (int i = 0; i < n; i++)
//     {
//         process_pair_expression(fin, i + 1);
//     }

//     return 0;
// }
// bool is_not_vaild = 0;
// bool is_dev_zero = 0;
// int calculate(string str)
// {
//     int vaildcount = 1;
//     stack<char> op;
//     stack<char> postfix;
//     for (char c : str)
//     {
//         if (vaildcount != 0 && vaildcount != 1)
//         {
//             is_not_vaild = 1;
//             return 0;
//         }
//         // 先转后缀，再计算
//         if (c == '(')
//         {
//             op.push(c);
//         }
//         else if (c == ')')
//         {
//             while (!op.empty() && op.top() != '(')
//             {
//                 postfix.push(op.top());
//                 op.pop();
//             }
//             if (!op.empty() && op.top() == '(')
//                 op.pop();
//         }
//         else if (c == '+' || c == '-')
//         {
//             vaildcount++;
//             while (!op.empty() && (op.top() == '*' || op.top() == '/' || op.top() == '+' || op.top() == '-'))
//             {
//                 postfix.push(op.top());
//                 op.pop();
//             }
//             op.push(c);
//         }
//         else if (c == '*' || c == '/')
//         {
//             vaildcount++;
//             while (!op.empty() && (op.top() == '*' || op.top() == '/'))
//             {
//                 postfix.push(op.top());
//                 op.pop();
//             }
//             op.push(c);
//         }
//         else // digital
//         {
//             vaildcount--;
//             postfix.push(c);
//         }
//     }
//     if (vaildcount != 0)
//     {
//         is_not_vaild = 1;
//         return 0;
//     }
//     while (!op.empty())
//     {
//         if (op.top() == '(')
//         {
//             is_not_vaild = 1;
//             return 0;
//         }
//         postfix.push(op.top());
//         op.pop();
//     }
//     // 开始读取
//     // 这还差一个倒转的办法
//     stack<char> temp;
//     while (!postfix.empty())
//     {
//         temp.push(postfix.top());
//         postfix.pop();
//     }
//     postfix = temp;

//     stack<int> res;
//     while (!postfix.empty())
//     {
//         if (postfix.top() == '+' || postfix.top() == '-' || postfix.top() == '*' || postfix.top() == '/')
//         {
//             int n2 = postfix.top() - '0';
//             res.pop();
//             int n1 = postfix.top() - '0';
//             res.pop();
//             if (postfix.top() == '+')
//                 res.push(n1 + n2);
//             if (postfix.top() == '-')
//                 res.push(n1 - n2);
//             if (postfix.top() == '*')
//                 res.push(n1 * n2);
//             if (postfix.top() == '/')
//             {
//                 if (n2 == 0)
//                 {
//                     is_dev_zero = 1;
//                     return 0;
//                 }
//                 res.push(n1 / n2);
//             }
//         }
//         else
//         {
//             res.push(postfix.top() - '0');
//         }
//         postfix.pop();
//     }
//     return res.top();
// }

// int main()
// {
//     ifstream fin("in.txt");
//     ofstream fout("out.txt");
//     int n;
//     fin>>n;
//     fin.ignore(10000, '\n');

//     for (int i = 1; i <= n; i++)
//     {
//         is_not_vaild = 0;
//         is_dev_zero = 0;
//         string s1, s2;
//         getline(fin, s1);
//         getline(fin, s2);
//         int res1 = calculate(s1);
//         int res2 = calculate(s2);
//         if (is_not_vaild)
//         {
//             fout << "测试用例" << i << "：" << "表达式" << i << "无效！" << "\n";
//         }
//         else if (is_dev_zero)
//         {

//             fout << "测试用例" << i << "：" << "表达式" << i << "除0出错！" << "\n";
//         }
//         else if (res1==res2)
//         {

//             fout << "测试用例" << i << "：" << "TRUE" << "\n";
//         }
//         else
//         {

//             fout << "测试用例" << i << "：" << "FALSE" << "\n";
//         }
//     }

//     return 0;
// }

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool is_not_valid = 0;
bool is_dev_zero = 0;

// 状态管理
bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

// 算结果，改错误
int getres(string exp)
{
    is_not_valid = 0;
    is_dev_zero = 0;
    int res;

    vector<char> postfix;
    stack<char> opstk;

    bool expect_num = 1; // 当前是否期待操作数

    // 改成后缀表达式，顺便判定valid
    for (int i = 0; i < exp.size(); i++)
    {
        char c = exp[i];
        if (!is_operator(c))
        {
            if (!expect_num)
            {
                is_not_valid = 1;
                return -1;
            }
            postfix.push_back(c);
            expect_num = 0;
        }
        else
        {
            if (c == '(') // 这里把左括号当作数字来看待合法即可，经过一个左括号对expect参数没有影响
            {
                if (!expect_num)
                {
                    is_not_valid = 1;
                    return -1;
                }
                opstk.push(c);
            }
            else if (c == ')')
            {
                if (expect_num)
                {
                    is_not_valid = 1;
                    return -1;
                }
                bool has_left = 0; // 需要防止一手没有左括号的情况
                while (!opstk.empty() && opstk.top() != '(')
                {
                    postfix.push_back(opstk.top());
                    opstk.pop();
                }
                if (!opstk.empty() && opstk.top() == '(')
                {
                    opstk.pop();
                    has_left = 1;
                }
                if (!has_left)
                {
                    is_not_valid = 1;
                    return -1;
                }
                expect_num = 0;
            }
            else if (c == '+' || c == '-')
            {
                if (expect_num)
                {
                    is_not_valid = 1;
                    return -1;
                }

                while (!opstk.empty() && opstk.top() != '(')
                {
                    postfix.push_back(opstk.top());
                    opstk.pop();
                }
                opstk.push(c);
                expect_num=1;
            }
            else if (c == '*' || c == '/')
            {
                if (expect_num)
                {
                    is_not_valid = 1;
                    return -1;
                }

                while (!opstk.empty() && (opstk.top() == '*' || opstk.top() == '/'))
                {
                    postfix.push_back(opstk.top());
                    opstk.pop();
                }
                opstk.push(c);
                expect_num = 1;
            }
        }
    }

    if (expect_num)
    {
        is_not_valid = 1;
        return -1;
    }

    while (!opstk.empty())
    {
        if (opstk.top() == '(' || opstk.top() == ')')
        {
            is_not_valid = 1;
            return -1;
        }
        postfix.push_back(opstk.top());
        opstk.pop();
    }

    // 计算已经合法的postfix,判定除零
    stack<int> numstk;
    for (char c : postfix)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (numstk.size() < 2)
            {
                is_not_valid = 1;
                return -1;
            }

            int n2 = numstk.top();
            numstk.pop();
            int n1 = numstk.top();
            numstk.pop();

            if (c == '+')
                numstk.push(n1 + n2);
            if (c == '-')
                numstk.push(n1 - n2);
            if (c == '*')
                numstk.push(n1 * n2);
            if (c == '/')
            {
                if (n2 == 0)
                {
                    is_dev_zero = 1;
                    return -1;
                }
                numstk.push(n1 / n2);
            }
        }
        else
        {
            numstk.push(c - '0');
        }
    }

    if (numstk.size() != 1)
    {
        is_not_valid = 1;
        return -1;
    }

    res = numstk.top();
    return res;
}

void process_pair_expression(ifstream &fin, ofstream &fout, int k)
{
    string exp1, exp2;
    getline(fin, exp1);
    getline(fin, exp2);

    int res1 = getres(exp1);
    bool exp1_not_valid = is_not_valid;
    bool exp1_dev_zero = is_dev_zero;

    int res2 = getres(exp2);
    bool exp2_not_valid = is_not_valid;
    bool exp2_dev_zero = is_dev_zero;

    fout << "测试用例" << k << "：";
    string ans = "";

    if (exp1_not_valid)
    {
        ans += "表达式1无效！";
    }
    else if (exp1_dev_zero)
    {
        ans += "表达式1除0出错！";
    }
    if (exp2_not_valid)
    {
        ans += "表达式2无效！";
    }
    else if (exp2_dev_zero)
    {
        ans += "表达式2除0出错！";
    }

    if (ans == "")
    {
        ans = res1 == res2 ? "TRUE" : "FALSE";
    }

    fout << ans << "\n";
}

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int n = 0;
    fin >> n;
    fin.ignore();
    for (int i = 0; i < n; i++)
    {
        process_pair_expression(fin, fout, i + 1);
    }

    return 0;
}