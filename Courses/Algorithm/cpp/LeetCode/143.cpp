/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
#include <vector>
#include<algorithm>
using namespace std;

 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
#include <vector>
#include<algorithm>
using namespace std;
 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr) return ;
        vector<ListNode*> List;
        //存储成数组，再双指针两边遍历
        ListNode* p1=head;
        while(p1!=nullptr)
        {
            List.push_back(p1);
            //可以与==和=写混相提并论的错误——p1=不写
            p1=p1->next;
        }
        int n=List.size();
        int left=1;
        int right=n-1;
        bool isleft=0;
        ListNode* p=head;
        for(int i=1;i<n;i++)
        {
            if(isleft)
            {
                p->next=List[left];
                left++;
                p=p->next;
            }
            else{
                p->next=List[right];
                right--;
                p=p->next;
            }
        //状态机记得要转换状态
            isleft=!isleft;
        }
        //链表重排要记得处理尾节点，防止再次进入原来的链表结构
      p->next=nullptr;
    }
};