/*3. 条件反转循环队列
【问题描述】

设计一个算法，利用一个顺序栈将一个循环队列中的所有元素倒过来，
使得队头变为队尾，队尾变为队头。同时队列中存在特殊标记元素（值为 -1），
这些元素在反转后必须保持原有的位置，其他元素需完全倒置。
【输入形式】
第一行输入一个整数n，表示循环队列的长度；
第二行输入n个整数，以空格分隔，表示循环队列的元素值，
输入按队列的顺序给出，即第一个数是队头元素，最后一个数是队尾元素。
【输出形式】
输出一行整数，表示倒置后的队列元素，元素之间以空格分隔，新的队头在最前面，新的队尾在最后面。
【样例输入】
5
1 2 3 -1 5
【样例输出】
5 3 2 -1 1
【样例说明】
【评分标准】

【类库使用要求】

不可以使用STL中的stack、queue、vector等库函数，可以使用字符串STL处理输入。

【说明】

要求自己设计实现栈或队列类*/

#include <iostream>
#include <algorithm>
using namespace std;
struct reverse_queue
{
    int *data;
    int size;
    int capacity;
    reverse_queue() : data(nullptr), size(0), capacity(0) {}
    void push(int x)
    {
        if (capacity == size)
        {
            capacity = capacity == 0 ? 1 : 2 * capacity;
            int *newdata = new int[capacity];
            for (int i = 0; i < size; i++)
                newdata[i] = data[i];
            delete[] data;
            data = newdata;
        }
        data[size] = x;
        size++;
    }
    void reverse()
    {
        int front = 0;
        int rear = size - 1;
        while (front < rear)
        {
            while (data[front] == -1 && front < rear)
                front++;
            while (data[rear] == -1 && front < rear)
                rear--;
            swap(data[front], data[rear]);
            front++;
            rear--;
        }
    }
};



int main()
{
    int n;
    cin >> n;
    reverse_queue q;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    q.reverse();
    for (int i = 0; i < q.size; i++)
        cout << q.data[i] << " ";
    return 0;
}