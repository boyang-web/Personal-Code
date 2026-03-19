// 栈实现队列
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> back;
    stack<int> front;
    MyQueue()
    {
    }

    void push(int x)
    {
        tranb();
        back.push(x);
    }

    int pop()
    {
        tranf();
        int res = front.top();
        front.pop();
        return res;
    }

    int peek()
    {
        tranf();
        return front.top();
    }

    bool empty()
    {
        if (back.empty() && front.empty())
            return true;
        return false;
    }

    void tranf() // 注意这里的双向倒腾
    {

        while (!back.empty())
        {
            front.push(back.top());
            back.pop();
        }
    }
    void tranb()
    {
        while (!front.empty())
        {
            back.push(front.top());
            front.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */