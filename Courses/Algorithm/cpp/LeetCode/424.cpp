/*
给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。

在执行上述操作后，返回 包含相同字母的最长子字符串的长度。

 

示例 1：

输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。
示例 2：

输入：s = "AABABBA", k = 1
输出：4
解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。
可能存在其他的方法来得到同样的结果。
*/

#include<string>
//窗口合法条件是串长-最大字母数<=k
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int left=0,right=0;
        int strlen=right-left;
        int maxchar=0;
        int freq[26]={0};//这个数组要初始化
        while(right<s.size())
        {
            int inter=s[right]-'A';
            freq[inter]++;
            maxchar=max(maxchar,freq[inter]);
            right++;
            strlen=right-left;
            while(strlen-maxchar>k)
            {
                int outer=s[left]-'A';
                freq[outer]--;
                left++;
            }
            strlen=right-left;
            ans=max(ans,strlen);
        }
        return ans;
    }
};