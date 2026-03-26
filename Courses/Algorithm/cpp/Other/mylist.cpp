/*
要点：
创建新节点要New 包括dummy
fin传入要用引用，确保文件 只被打开一次
搞清楚getline是把 流 读入 串 ;stringstream 是把 串 变成 流
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
};

void coutlist(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

ListNode *cinlist_line(ifstream &fin) // 注意这里传引用
{
    string line;
    if (!getline(fin, line))//注意查空的手法，这里如果正常就直接读进来了
        return nullptr;
    stringstream ss(line);

    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;

    int x;
    while (ss >> x)
    {
        p->next = new ListNode(x);
        p = p->next;
    }
    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

void merge_two()
{
    ifstream fin("tempfile/mylist.txt");

    ListNode *l1 = cinlist_line(fin);
    ListNode *l2 = cinlist_line(fin);

    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    while (l1 != nullptr || l2 != nullptr)
    {
        if (l1 == nullptr)
        {
            p->next = l2;
            break;
        }
        else if (l2 == nullptr)
        {
            p->next = l1;
            break;
        }
        else
        {
            if (l1->val > l2->val)
            {
                p->next = l2;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                l1 = l1->next;
            }
        }
        p = p->next;
    }
    coutlist(dummy->next);
    delete dummy;
}

void remove_duplicates()
{
    ifstream fin("tempfile/mylist.txt");
    ListNode *head = cinlist_line(fin);
    ListNode *fast = head, *slow = head;
    while(fast!=nullptr)
    {
        if(fast->val!=slow->val)
        {
            slow=slow->next;
            slow->val=fast->val;
        }
        fast=fast->next;
    }
    slow->next=nullptr;//链表截断的操作
    coutlist(head);
   
}
void writefile()
{
    ofstream fout("tempfile/mylist.txt");

    // 二路并归输入
    // fout << "1 3 5 7 9";
    // fout << "\n";
    // fout << "2 3 4 6 8";

    // 原地去重输出
    // fout << "1 1 2 2 3 3 3 4 4 4 4";

    
}

int main()
{
    writefile();
    // merge_two();
    // remove_duplicates();
    return 0;
}