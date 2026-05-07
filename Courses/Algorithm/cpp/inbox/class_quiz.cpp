#include <iostream>

using namespace std;

struct Queue
{
    int *data;
    int front;
    int size;
    int capacity;
    Queue():data(nullptr),front(0),size(0),capacity(0){}
    void enqueue(int x)
    {
        if(front+size==capacity)
        {
            capacity=capacity==0?1:2*capacity;
            int *newdata=new int[capacity];
            for(int i=0;i<size;i++)
            {
                newdata[i]=data[front+i];
            }
            delete[] data;
            data=newdata;
        }
        data[front+size]=x;
        size++;
    }
    void dequeue()
    {
        front++;
        size--;
    }
    int getfront()
    { 
        return data[front];
    }
    bool isEmpty()
    { 
        return size==0;
    }
    int getsize()
    { 
        return size;
    }
};

int main()
{
    int n;//123456,12345
    cin>>n;
    Queue q1,q2,q3;
    for(int i=1;i<=(n+1)/2;i++)
    {
        q1.enqueue(i);

    }
    for(int i=1+(n+1)/2;i<=n;i++)
    {
        q2.enqueue(i);
    }
    for(int i=1;i<=(n+1)/2;i++)
    {
        if(!q1.isEmpty())
        {
            q3.enqueue(q1.getfront());
            q1.dequeue();
        }
        if(!q2.isEmpty())
        {
            q3.enqueue(q2.getfront());
            q2.dequeue();
        }
    }
    while(!q3.isEmpty())
    {
        cout<<q3.getfront()<<" ";
        q3.dequeue();
    }
    return 0;
}