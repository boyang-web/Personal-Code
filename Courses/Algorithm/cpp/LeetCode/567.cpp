/*
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的 排列。如果是，返回 true ；否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。



示例 1：

输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
示例 2：

输入：s1= "ab" s2 = "eidboaoo"
输出：false*/

// 重点是在窗口移动的过程中,维护了什么,何时维护
// 维护了match 和window
//这一题对滑动窗口又了解一些了,要注意最后一个窗口可能无法扫描到的情况
#include <string>
#include <map>

using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.empty() || s2.empty() || s1.size() > s2.size())
            return false;
        map<char, int> target;
        map<char, int> window;

        int left = 0, match = 0;
        int len = s1.size();

        for (int i = 0; i < len; i++)
        {
            target[s1[i]]++;
        }
        for (int i = 0; i < len; i++)
        {
            if (target.count(s2[i]))
            {
                window[s2[i]]++;
                if (window[s2[i]] == target[s2[i]])
                    match++;
            }
        }
        if (match == target.size())
                return true;
        while (left + len < s2.size())
        {
            
            char outer = s2[left];
            if (target.count(outer))
            {
                if (target[outer] == window[outer])
                    match--;
                window[outer]--;
            }
            char inter=s2[left+len];
            if(target.count(inter))
            {
                 window[inter]++;
                if(target[inter]==window[inter])
                match++;
               
            }
            left++;
            if (match == target.size())
                return true;
        }
        return false;
    }
};