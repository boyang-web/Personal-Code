/*1. 基于循环队列的缓冲区管理
【问题描述】
  设计一个循环队列（Circular Queue）来模拟数据缓冲区
  （假定缓冲区中的数据都是整数）的管理。循环队列的容量固定为 k(0=<k<=100)，支持以下操作：
  enqueue(value)：向队列尾部插入一个元素。如果队列已满，
  则丢弃最早入队的元素（即覆盖最旧的数据），再插入新元素。
  dequeue()：移除并返回队列头部的元素。如果队列为空，返回 -1。
  get_oldest()：返回最早入队的元素（不移除）。如果队列为空，返回 -1。
  get_latest()：返回最近入队的元素（不移除）。如果队列为空，返回 -1。
要求：
  所有操作的时间复杂度必须为 O(1)。不能使用STL的队列容器，
  必须手动实现循环队列(不一定按照教材，可自行定义，注意分配的空间都用来存放数据，不需要空一个）。
提示：请正确处理循环队列的所有边界情况，包括队列空、队列满、覆盖写入等情况。
【输入形式】
  第一行：k（队列容量）和 m（操作数量）。
  接下来 m 行，每行一个操作：
   enqueue x（插入元素 x）
   dequeue（移除并返回头部元素）
   get_oldest（查询最早元素）
   get_latest（查询最新元素）
【输出形式】
   对于 dequeue、get_oldest、get_latest 操作，输出对应的返回值。
【样例输入】
3 8
enqueue 1
enqueue 2
enqueue 3
enqueue 4
get_oldest
dequeue
get_latest
dequeue
*/
#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct circular_queue
{
  vector<int> q;
  int front, rear;
  int capacity;
  circular_queue(int k)
  {
    front = 0;
    rear = 0;
    capacity = k + 1;
    q.resize(capacity);
  }
  void enqueue(int val)
  {
    q[rear] = val;
    rear = (rear + 1) % capacity;
    if (rear == front)
      front = (front + 1) % capacity;
  }
  int dequeue()
  {
    if (rear == front)
      return -1;
    int res = q[front];
    front = (front + 1) % capacity;
    return res;
  }
  int get_oldest() // 就是front
  {
    return rear == front ? -1 : q[front];
  }
  int get_latest() // 就是rear-1
  {
    return rear == front ? -1 : q[(rear + capacity - 1) % capacity];
  }
};

int main()
{
  int k, m;
  cin >> k >> m;
  circular_queue q(k);
  for (int i=0; i < m; i++)
  {
    string instruction;
    cin >> instruction;
    if (instruction == "enqueue")
    {
      int val;
      cin>>val;
      q.enqueue(val);
    }
    else if (instruction == "dequeue")
    {
      cout<<q.dequeue()<<"\n";
    }
    else if (instruction == "get_oldest")
    {
      cout<<q.get_oldest()<<"\n";
    }
    else//latest
    {
      cout<<q.get_latest()<<"\n";
    }
  }

  return 0;
}
