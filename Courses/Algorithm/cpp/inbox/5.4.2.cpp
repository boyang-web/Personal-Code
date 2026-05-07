//前序中序求后序

#include<iostream>
#include<string>

using namespace std;
string post;
void getpost(string pre,string mid)
{
    int sz=pre.size();
    if(sz==0)
    return;
    if(sz==1)
    {
        post+=pre;
        return;
    }
    int k=mid.find(pre[0]);
    getpost(pre.substr(1,k),mid.substr(0,k));
    getpost(pre.substr(k+1),mid.substr(k+1));
    post+=pre[0];
}

int main()
{
    string pre,mid;
    cin>>mid>>pre;
    getpost(pre,mid);
    cout<<post;

    return 0;
}