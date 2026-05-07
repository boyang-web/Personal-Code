/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。


示例 1:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

*/

//使用辅助栈
#include <stack>
#include<iostream>
#include<queue>
using namespace std;
class MinStack
{
public:
    stack<int> stk;
    stack<int> minstk;
    MinStack()
    {
    }

    void push(int val)
    {
        stk.push(val);
        if(!minstk.empty())
        minstk.push(min(minstk.top(),val));
        else
        minstk.push(val);
    }

    void pop()
    {
        stk.pop();
        minstk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */