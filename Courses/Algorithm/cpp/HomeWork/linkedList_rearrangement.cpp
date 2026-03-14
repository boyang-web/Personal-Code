/*
2. 链表重排
【问题描述】
给定一个单链表 L1→L2→⋯→Ln−1→Ln，
请编写程序将链表重新排列为 Ln→L1→Ln−1→L2→⋯。
例如：给定L为1→2→3→4→5→6，则输出应该为6→1→5→2→4→3。
【输入形式】
每个输入包含1个测试用例。
每个测试用例第1行给出第1个结点的地址和结点总个数，
即正整数N (≤105)。结点的地址是5位非负整数，NULL地址用−1表示。
接下来有N行，每行格式为：
Address Data Next

其中Address是结点地址；Data是该结点保存的数据，
为不超过105的正整数；Next是下一结点的地址。
题目保证给出的链表上至少有两个结点。
【输出形式】
对每个测试用例，顺序输出重排后的结果链表，
其上每个结点占一行，格式与输入相同。
【样例输入】
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
【样例输出】
68237 6 00100
00100 1 99999
99999 5 12309
12309 2 00000
00000 4 33218
33218 3 -1
【解题思路】（仅供参考，可以有其他解法）
定义链表结点：包含三元组，addr存储该结点本身的地址
（可以定义为int或string类型，
如果是int类型要注意位数不足时的输出时格式），
value存该结点序号，next为指向下一结点的指针。
从输入数据构建链表，根据value值将其插入到链表相应位置；
按要求重排链表；
输出重排后的链表，
输出内容为："当前节点.addr"
"当前结点.value"
"下一结点.addr(尾节点输出-1）"
*/

/*
题目讲的很不清楚
基本上就是先把顺序理清楚，再一头一尾排序
*/
//要点就是最后一列可以通过第一列生成，那么最后一列可以脱离考虑，变相简化了问题
//问题层次规模一复杂就迷糊了，需要训练注意力集中能力和代码阅读能力
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
//先读取，塞入map
//再转到vector
//双指针调正
struct Node{
    string addr;
    int value;
    string nextAddr;
};
int main()
{
    //输入
    string firstaddr;
    int n;
    cin>>firstaddr>>n;

    map<string , Node*> nodes;
    for(int i=0;i<n;i++)
    {
        Node* nodetemp=new Node;
        cin>>nodetemp->addr>>nodetemp->value>>nodetemp->nextAddr;
        nodes[nodetemp->addr]=nodetemp;
    }

    //正常排序
    vector<Node*> list(n);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        list[0]=nodes[firstaddr];
        else{
            list[i]=nodes[list[i-1]->nextAddr];
        }
    }

    //双指针遍历
    vector<Node*> target(n);
    int left=0,right=n-1;
    bool isright=1;
    for(int i=0;i<n;i++)
    {
        if(isright)
        target[i]=list[right--];
        else
        target[i]=list[left++];
        isright=!isright;
    }

    //输出
    for(int i=0;i<n;i++)
    {
        string nextaddr=(i==n-1)?"-1":target[i+1]->addr;
        cout<<target[i]->addr<<" "<<target[i]->value<<" "<<nextaddr<<endl;
    }
    
    
    return 0;
}