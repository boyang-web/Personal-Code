/*请你设计一个队列，支持在前，中，后三个位置的 push 和 pop 操作。

请你完成 FrontMiddleBack 类：

FrontMiddleBack() 初始化队列。
void pushFront(int val) 将 val 添加到队列的 最前面 。
void pushMiddle(int val) 将 val 添加到队列的 正中间 。
void pushBack(int val) 将 val 添加到队里的 最后面 。
int popFront() 将 最前面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
int popMiddle() 将 正中间 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
int popBack() 将 最后面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
请注意当有 两个 中间位置的时候，选择靠前面的位置进行操作。比方说：

将 6 添加到 [1, 2, 3, 4, 5] 的中间位置，结果数组为 [1, 2, 6, 3, 4, 5] 。
从 [1, 2, 3, 4, 5, 6] 的中间位置弹出元素，返回 3 ，数组变为 [1, 2, 4, 5, 6] 。*/

#include <vector>

using namespace std;
class FrontMiddleBackQueue
{
    vector<int> q;
    // 类似迭代器的左闭右开，mid实时计算
    int mid, rear;

public:
    FrontMiddleBackQueue()
    {
        mid = 0, rear = 0;
    }

    void pushFront(int val)
    {
        q.insert(q.begin(), val);
        rear++;
    }

    void pushMiddle(int val)
    {
        mid = (rear) / 2;//非常隐蔽的错误。插入和删除mid的公式不一样
        q.insert(q.begin() + mid, val);
        rear++;
        
    }

    void pushBack(int val)
    {
        q.insert(q.end(), val);
        rear++;
    }

    int popFront()
    {
        if (q.empty())
            return -1;
        int temp = q[0];
        q.erase(q.begin());
        rear--;
        return temp;
    }

    int popMiddle()
    {
       mid = (rear-1) / 2;
        if (q.empty())
            return -1;
        int temp = q[mid];
        q.erase(q.begin()+mid);
        rear--;
        return temp;
    }

    int popBack()
    {
        if (q.empty())
            return -1;
        int temp = q[rear - 1];
        q.erase(q.end() - 1);
        rear--;
        return temp;
    }
};
