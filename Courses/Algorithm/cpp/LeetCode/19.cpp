/*
删除倒数第n个节点
注意不要内存泄漏

要点：
要考虑各种情况做好防御性编程，比如此题删除第一个元素的情形
或者是依旧使用dummy节点把头删除转化为中间删除
*/
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// dummy node version
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        } // slow走到了倒数n+1节点
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummy->next;
    }
};
// additional process version
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (fast == nullptr)
            return head->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        } // slow走到了倒数n+1节点
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};