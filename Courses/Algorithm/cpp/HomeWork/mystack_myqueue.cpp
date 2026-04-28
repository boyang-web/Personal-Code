

// //打印杨辉三角
// #include<iostream>
// #include<queue>
// using namespace std;

// int main()
// {

//     int n=0;
//     cin>>n;
//     queue<int> q;
//     q.push(1);
//     cout<<"1"<<"\n";
//     for(int i=1;i<n;i++)
//     {
//         int cur=0;
//         for(int j=1;j<=i;j++)
//         {
//             cur+=q.front();

//             cout<<cur<<" ";

//             q.push(cur);
//             cur=q.front();
//             q.pop();

//         }
//         q.push(1);
//         cout<<"1"<<"\n";
//     }
//     return 0;
// }

// 实现一个栈
#include <iostream>
#include <string>
using namespace std;

struct stack
{
    int *data;
    int size;
    int capacity;
    stack() : data(nullptr), size(0), capacity(0) {}

    void push(int x)
    {
        if (capacity == size)
        {
            capacity = capacity == 0 ? 1 : 2 * capacity;
            int *newdata = new int[capacity];
            for (int i = 0; i < size; i++)
                newdata[i] = data[i];
            data = newdata;
        }
        data[size] = x;
        size++;
    }

    void pop()
    {
        if (size == 0)
            return;
        size--;
    }

    int top()
    {
        if (size == 0)
            return -1;
        return data[size - 1];
    }

    bool empty()
    {
        return size == 0;
    }
};

// // 进制转换
// int main()
// {

//     int n, k;
//     cin >> n >> k;
//     if(n==0)
//     {
//         cout<<"0";
//     }
//     stack stk;
//     while (n != 0)
//     {
//         stk.push(n % k);
//         n = n / k;
//     }
//     while (!stk.empty())
//     {
//         if (stk.top() == 10)
//             cout << "A";
//         if (stk.top() == 11)
//             cout << "B";
//         if (stk.top() == 12)
//             cout << "C";
//         if (stk.top() == 13)
//             cout << "D";
//         if (stk.top() == 14)
//             cout << "E";
//         if (stk.top() == 15)
//             cout << "F";
//         else
//             cout << stk.top();
//         stk.pop();
//     }
//     return 0;
// }

int main()
{
    int n;
    cin>>n;
    stack stk;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        stk.push(temp);
    }
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}