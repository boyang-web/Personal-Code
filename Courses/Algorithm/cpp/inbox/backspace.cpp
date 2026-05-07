/*【问题描述】
小明的键盘坏了，每次按下字符时会随机多输入一个退格符 #（例如输入 a#b 实际显示为 b）。
现给定一个字符串 s，其中 # 表示退格符，它会删除其前一个有效字符。
请编写程序，模拟键盘输出最终显示的字符串。
【输入形式】
输入一行字符串 s（仅包含小写字母和 # 符号）。
【输出形式】
输出处理后的字符串。若结果为空，则输出空行。
【样例输入1】
a#b#c
【样例输出1】
c
【样例输入2】
ab#c##
【样例输出2】（说明：空行）

【评分标准】
10个测试用例，按通过比例评分。
【评分标准】
10个测试用例，按通过比例评分。
【样例说明】
样例的输入只有1行，样例输出只有1行，请忽略为阅读方便而插入的空白行。
【类库使用要求】
不可以使用STL中的stack、queue、deque、vector等库函数，可以使用字符串STL处理输入。
【说明】
要求自己设计实现栈或队列类*/

#include <string>
#include <iostream>
using namespace std;

struct stack
{
    char *data;
    int size;
    int capacity;
    stack() : data(nullptr), size(0), capacity(0) {}

    void push(int val)
    {
        if (size == capacity) // 扩容
        {
            capacity = 0 ? 1 : 2 * capacity;
            char *newdata = new char[capacity];
            for (int i = 0; i < size; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
        }
        data[size] = val;
        size++;
    }
    void pop()
    {
        if (size != 0)
            size--;
    }
};

int main()
{
    string input;
    stack stk;
    cin >> input;
    for (auto x : input)
    {
        if (x == '#')
            stk.pop();
        else
            stk.push(x);
    }
    for (int i = 0; i < stk.size; i++)
        cout << stk.data[i];
    cout << "\n";
    return 0;
}