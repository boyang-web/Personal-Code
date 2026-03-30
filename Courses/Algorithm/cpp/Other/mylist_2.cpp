/*自己实现双向链表结构并完成以下操作
1.读取两组单调递增的数据进入两个链表
2.并归成一个单调递增的链表
3.反转这个链表并输出
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct ListNode
{
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

int main()
{
    ListNode *dummy1 = new ListNode(0);
    ListNode *p1 = dummy1;
    ListNode *dummy2 = new ListNode(0);
    ListNode *p2 = dummy2;
    // 输入
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    stringstream ss1(line1), ss2(line2);
    int x;
    while (ss1 >> x)
    {
        ListNode *temp = new ListNode(x);
        temp->prev = p1;
        p1->next = temp;
        p1 = p1->next;
    }
    while (ss2 >> x)
    {
        ListNode *temp = new ListNode(x);
        temp->prev = p2;
        p2->next = temp;
        p2 = p2->next;
    }
    // 归并
    ListNode *dummy3 = new ListNode(0);
    ListNode *p3 = dummy3;
    p1 = dummy1->next;
    p2 = dummy2->next;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->val < p2->val)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3->next->prev = p3;
        p3 = p3->next;
    }
    if (p1 == nullptr && p2 != nullptr)
    {
        p3->next = p2;
        p3->next->prev = p3;
    }
    if (p2 == nullptr && p1 != nullptr)
    {
        p3->next = p1;
        p3->next->prev = p3;
    }

    // 倒转
    p3 = dummy3->next;
    if (p3 != nullptr)
        p3->prev = nullptr;
    ListNode *newHead = nullptr;
    while (p3 != nullptr)
    {
        swap(p3->next, p3->prev);
        newHead = p3;
        p3 = p3->prev;
    }

    // 输出
    p3 = newHead;
    while (p3 != nullptr)
    {
        cout << p3->val << " ";
        p3 = p3->next;
    }

    return 0;
}