//后序中序求前序

#include<string>
#include<iostream>

using namespace std;

void getpre(string mid,string post)
{
    
    int sz=mid.size();
    if(sz==0)
    return;
    cout<<post[sz-1];
    if(sz==1)
    return;
    int k=mid.find(post[sz-1]);
    getpre(mid.substr(0,k),post.substr(0,k));
    getpre(mid.substr(k+1),post.substr(k,sz-k-1));
}

string pre,mid,post;
int main()
{
    cin>>mid>>post;
    getpre(mid,post);
    return 0;
}