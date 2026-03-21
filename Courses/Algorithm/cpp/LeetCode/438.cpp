/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。



示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
*/
#include <string>
#include <vector>
#include<map>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        
        vector<int> ans={};
        if(s.empty()||p.empty()||p.size()>s.size()) return ans;
        
        map<char ,int> target;
        map<char,int> window;
        int left=0,right=0,match=0;

        for(char c:p)
        target[c]++;

        //初始化最开始的窗口
        for(;right<p.size();right++)
        {
            if(target.count(s[right]))
            {
                window[s[right]]++;
                if(window[s[right]]==target[s[right]])//只有笔误了
                match++;
            }
        }
        if(match==target.size()) ans.push_back(left);

        while(right<s.size())//进入主逻辑
        {
            char c=s[left];
            if(target.count(c))
            {
                if(window[c]==target[c])
                match--;
                window[c]--;
            }
            left++;
            
            char d=s[right];
            if(target.count(d))
            {
                window[d]++;
                if(window[d]==target[d])
                match++;
            }
            right++;
            if(match==target.size()) ans.push_back(left);
        }
        return ans;
    }
};