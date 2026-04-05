/*给你两个字符串 haystack 和 needle ，
请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
如果 needle 不是 haystack 的一部分，则返回  -1 。

 

示例 1：

输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0*/
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return kmp_find(haystack,needle);
    }

    vector<int> build_pi(string p)
    {
        vector<int> pi(p.size());
        int j=0;
        for(int i=1;i<p.size();i++)
        {
            j=pi[i-1];
            while(j>0&&p[j]!=p[i])
            j=pi[j-1];
            if(p[j]==p[i])
            j++;
            pi[i]=j;
        }
        return pi;
    }

    int kmp_find(string s,string p)
    {
        vector<int> pi=build_pi(p);
        int j=0;
        int i=0;
        while(i<s.size())
        {
            while(j>0&&s[i]!=p[j])
            {
                j=pi[j-1];
            }
            if(s[i]==p[j])
            {
                j++;
            }
            i++;//注意这里的先后顺序，i先++的，所以return 不用+1；
            if(j==p.size())
            return i-p.size();
        }
        return -1;
    }
};
//测试
// vector<int> build_pi(string p)
//     {
//         vector<int> pi(p.size());
//         int j=0;
//         for(int i=1;i<p.size();i++)
//         {
//             j=pi[i-1];
//             while(j>0&&p[j]!=p[i])
//             j=pi[j-1];
//             if(p[j]==p[i])
//             j++;
//             pi[i]=j;
//         }
//         return pi;
//     }

// int main()
// {
//     for(auto x:build_pi("aaabaab"))
//     cout<<x;
//     return 0;
// }
