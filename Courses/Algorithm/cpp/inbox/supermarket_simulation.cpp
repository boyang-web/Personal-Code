/*1. 队列-超市模拟(1)
【问题描述】

模拟超市排队的行为。最初，有n个队列（1，2，…，n），每个队列都有一些顾客。之后可能会发生两个事件：
ENTERS：顾客到达队列。如果队列在1到n之间，则顾客到达该队列的末尾。否则，该事件将被忽略；
LEAVES：顾客离开队列。如果队列在1到n之间，并且该队列不为空，
则该队列的第一个顾客将离开该队列。否则，该事件将被忽略。
【类库使用要求】可以使用STL类库
【输入形式】

1.     输入从队列的数量n（严格意义上为正的自然数）开始。

2.     按照n行，每个队列一行，每个行按照顾客到达队列的顺序，列出顾客名字。

3.     然后空一行。

4.     事件描述（ENTERS 或者LEAVES）后面，跟着顾客名字和和队列序号（正整数）。

【输出形式】

1.     首先，按离开的顺序打印离开队列的顾客姓名。

2.     然后，按顺序打印n个队列的最终内容。


【样例输入】

5
Lisa
Tom
John
Jerry Mary
Eric

LEAVES 1
LEAVES 2
ENTERS Harry 2
【样例输出】

DEPARTS
Lisa
John

FINAL CONTENTS
queue 1: Tom
queue 2: Harry
queue 3: Jerry Mary
queue 4:
queue 5: Eric*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    vector<queue<string>> supermarket;
    vector<string> departs;
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);

        queue<string> tempq;
        string token;
        while (ss >> token)
            tempq.push(token);

        supermarket.push_back(tempq);
    }

    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            continue;

        string event;
        stringstream ss(line);
        ss >> event;

        if (event == "ENTERS")
        {
            string person;
            int sign;
            ss >> person >> sign;
            if (sign >= 1 && sign <= n)
                supermarket[sign - 1].push(person);
        }
        else if (event == "LEAVES")
        {
            int sign;
            ss >> sign;
            if (sign >= 1 && sign <= n && !supermarket[sign - 1].empty())
            {
                departs.push_back(supermarket[sign - 1].front());
                supermarket[sign - 1].pop();
            }
        }
    }

    // 输出
    cout << "DEPARTS" << "\n";
    for (string s : departs)
        cout << s << "\n";
    cout << "\n";
    cout << "FINAL CONTENTS" ;
    for (int i = 0; i < n; i++)
    {
        
        cout <<"\n"<< "queue " << i + 1 << ":";
        while (!supermarket[i].empty())
        {
            cout << " " << supermarket[i].front();
            supermarket[i].pop();
        }
        
    }
    return 0;
}