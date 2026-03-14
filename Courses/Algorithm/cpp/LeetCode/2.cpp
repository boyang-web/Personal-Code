/*
题目条件已经逆序完成，采用节点模式写加法器即可
要点：
1.为了统一加法器模式，在链表中使用dummy技巧
2.创建指针的时候一定要定义，用new调用构造函数的结构初始化
    不然会出现野指针
*/

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{ 
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0), *p3 = dummy;
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0, sum, n1, n2;

        while (p1 != nullptr || p2 != nullptr)
        {
            n1 = p1 ? p1->val : 0;
            n2 = p2 ? p2->val : 0;

            sum=n1+n2+carry;
            carry=sum/10;
            ListNode *node = new ListNode(sum%10);
            p3->next = node;
            p3 = p3->next;

            if (p1 != nullptr)
                p1 = p1->next;
            if (p2 != nullptr)
                p2 = p2->next;
        }
        if (carry == 1)
            p3->next = new ListNode(1);
        return dummy->next;
    }
};