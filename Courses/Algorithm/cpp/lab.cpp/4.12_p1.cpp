#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct ListNode
{
    vector<string> cur;
    ListNode *next;
    ListNode() : cur(), next(nullptr) {}
    ListNode(vector<string> v) : cur(v), next(nullptr) {}
};

string type="refin";
void process(ifstream &fin, ofstream &fout, int k)
{
    if (type == "refin")
        fin >> type;
    fout << "第" << k << "个" << type << "样例:" << "\n";
    if (type != "int" && type != "char")
    {
        fout << "未知的数据类型:" << type;
        while (true)
        {
            if (!(fin >> type) || type == "int" || type == "char")
                break;
        }
        return;
    }
    string curtype=type;
    type = "refin";

    ListNode *L1=new ListNode();
    ListNode *L2=new ListNode();

    int c1, c2;
    int n, m;
    for (int i = 0; i < 2; i++)
    {
        
        fin >> n >> m;
        ListNode *dummy = new ListNode();
        ListNode *p = dummy;

        for (int j = 0; j < n; j++)
        {
            vector<string> temp;
            for (int k = 0; k < m; k++)
            {
                string tmp;
                fin >> tmp;
                temp.push_back(tmp);
            }
            p->next = new ListNode(temp);
            p = p->next;
        }
        if (i == 0)
        {
            c1 = m;
            L1 = dummy->next;
        }
        else
        {
            c2 = m;
            L2 = dummy->next;
        }
        delete dummy;
    }
    int first_c, second_c;
    fin >> first_c >> second_c;
    if (first_c > c1 || second_c > c2||first_c<1||second_c<1)
    {
        fout << "列号超出范围!" << "\n";
        return;
    }
    // 主逻辑
    ListNode *p1=L1;
    while (p1 != nullptr)
    {
        ListNode *p2=L2;
        while (p2 != nullptr)
        {
            bool valid=false;
            vector<string> v1=p1->cur;
            vector<string> v2=p2->cur;
            if(curtype=="int")
            {
                valid=stoi(v1[first_c-1])>stoi(v2[second_c-1]);
            }
            else if(curtype=="char")
            valid=v1[first_c-1]>v2[second_c-1];


            if(valid)
            {
                for(auto x:v1)
                {
                    fout<<x<<" ";
                }
                for(auto x:v2)
                {
                    fout<<x<<" ";    
                }
                fout<<"\n";
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int n;
    fin >> n;
    for (int i = 1; i < n; i++)
    {
        process(fin, fout, i);
        fout <<endl;
    }
    process(fin, fout, n);
    return 0;

}