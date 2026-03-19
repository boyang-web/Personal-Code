//队列实现栈

#include<queue>
using namespace std;
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
         tran();
    }
    
    int pop() {
       
        int res=q.front();
        q.pop();
        return res;
    }
    
    int top() {
        int res=q.front();
        return res;
    }
    
    bool empty() {
        return q.empty();
    }

    void tran()//注意这里的倒腾
    {
        int n=q.size();
        for(int i=1;i<n;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */