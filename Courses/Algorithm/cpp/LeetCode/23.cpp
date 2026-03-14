/*
合并K个有序链表
要点1：掌握优先级列表自定义比较函数的手法
要点2：在对任何一个节点操作之前都需要问自己是否可能为空
要点3：还是要将实际操作的内存和指针变量分开，比如本题对k个链表操作，但不需要k个指针
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include<vector>
#include<queue>
using namespace std;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        ListNode *dummy = new ListNode(0), *p = dummy;

        auto cmp = [](ListNode *a, ListNode *b)
        { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

        for (ListNode *head : lists)
            if (head != nullptr)
                pq.push(head);

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            if (node->next != nullptr)
                pq.push(node->next);
            p->next = node;
            p = p->next;
        }
        return dummy->next;
    }
};