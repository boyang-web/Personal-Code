/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。



示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */
#include <string>
#include <map>
#include<iostream>
using namespace std;
// 这个题就比模板更灵活了一些
//  class Solution
//  {
//  public:
//      int lengthOfLongestSubstring(string s)
//      {
//          if (s.empty())
//              return 0;
//          map<char, int> window;
//          int left = 0, right = 0;
//          int res = 0;
//          while (right < s.size())
//          {
//              char c = s[right];
//              window[c]++;
//              right++;
//              while (window[c] > 1)
//              {
//                  window[s[left]]--;
//                  left++;
//              }
//              res = max(res, right - left);
//          }
//          return res;
//      }
//  };

// 二周目
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.size()==1) return 1;
        int left = 0, right = 0;
        int res = 0;
        map<char, int> mp;
        while (right < s.size())
        {
            mp[s[right]]++;
            while(mp[s[right]]>1)
            {
                mp[s[left]]--;
                left++;
                
            }
            res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};


int main()
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("pwwkew");
    return 0;
}
//abcabcbb