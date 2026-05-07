#include <iostream>
#include <string>
using namespace std;
struct Node
{
    char c;
    Node *next;
    Node(char ch) : c(ch), next(nullptr) {}
};

int main()
{
    string input;
    cin >> input;
    Node *dummy = new Node(0);
    Node *p = dummy;
    for (int i = 0; i < input.size(); )
    {
        if (i + 2 < input.size() && input[i] == 'a' && input[i + 1] == 'b' && input[i + 2] == 'c')
            i += 3;
        else
        {
            Node *temp = new Node(input[i]);
            p->next = temp;
            p = p->next;
            i++;
        }
    }

    Node *p1 = dummy->next;
    while (p1 != nullptr)
    {
        cout << p1->c;
        p1 = p1->next;
    }
    return 0;
}