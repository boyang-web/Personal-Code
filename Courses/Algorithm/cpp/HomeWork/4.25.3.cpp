
#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int n) : val(n), next(nullptr) {}
};

void dex(Node *p, int x)
{
    if(p==nullptr||p->next==nullptr)
    return ;
    if(p->next->val==x)
    {
        p->next=p->next->next;
        
    }
    dex(p->next,x); 
        
}

int main()
{
    int n;
    cin >> n;
    Node *dummy = new Node(0);
    Node *p = dummy;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        Node *tempN = new Node(temp);
        p->next = tempN;
        p = p->next;
    }

    int x;
    cin>>x;
    dex(dummy,x);

    Node *p1 = dummy->next;
    while (p1 != nullptr)
    {
        cout << p1->val<<" ";
        p1 = p1->next;
    }

    return 0;
}