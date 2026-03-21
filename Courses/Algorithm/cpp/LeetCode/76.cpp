//堪比初见dfs的学习时长
//最终需要记住的是窗口滑动可以不用状态机,while套while即可,最重要的是何时更新答案



/*
给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，
使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。

测试用例保证答案唯一。

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
*/

// 滑动窗口，注意左右都是从同一边开始运动的
// 一种状态机的感觉，左右轮换

// 错误很多，再写一版
//  #include<string>
//  using namespace std;
//  class Solution
//  {
//  public:
//      string minWindow(string s, string t)
//      {
//          string res;
//          int minlen=s.size();
//          int left=0,right=0;
//          bool is_right=true;
//          while(right!=s.size()-1)
//          {
//              while(!is_contain(s.substr(left,right-left),t))
//              {
//                  if(is_right)
//                  right++;
//                  else
//                  left++;
//              }
//              if(minlen>right-left)
//              {
//                  minlen=right-left;
//                  res=res.substr(left,minlen);
//              }
//              is_right=!is_right;
//          }
//          return res;
//      }

//     // 判断是否包含
//     bool is_contain(string s, string t)
//     {
//         bool res = true;
//         for (auto &x : t)
//             if (!s.count(x))
//                 res = false;
//         return res;
//     }
// };

// 注意这是要考虑重复元素的，所以哈希表比较合理
// 还是有一百个问题,算了，直接学最优解
// #include <string>
// #include <map>
// using namespace std;
// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         string res="";
//         map<char, int> window;
//         map<char, int> target;
//         int left = 0, right = 0;
//         for (auto &x : t)
//             target[x]++;
//         window[s[0]]++;
//         bool is_right = true;
//         while (right != s.size())
//         {
//             while (!is_contain(window, target) && is_right)
//             {
//                 right++;
//                 window[s[right]]++;
//             }
//             while (is_contain(window, target) && !is_right)
//             {
//                 window[s[left]]--;
//                 left++;
//             }
//             left--;
//             window[s[left]]++;

//             res=s.substr(left,right-left);
//             is_right=!is_right;
//         }
//         return res;
//     }
//     bool is_contain(map<char, int> window, map<char, int> target)
//     {
//         for (auto &x : target)
//             if(window[x.first]<x.second)
//                 return false;
//         return true;
//     }
// };

// ai最优
// 但我不太喜欢这个formed的形式
//  #include <string>
//  #include <unordered_map>
//  #include <climits>
//  using namespace std;

// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         if (s.empty() || t.empty()) return "";

//         unordered_map<char, int> need;
//         unordered_map<char, int> window;

//         for (char c : t)
//             need[c]++;

//         int required = need.size(); // 需要满足的字符种类数
//         int formed = 0;             // 当前已满足的字符种类数

//         int left = 0, right = 0;
//         int start = 0;              // 最优答案的起点
//         int minLen = INT_MAX;       // 最优答案长度

//         while (right < s.size())
//         {
//             char c = s[right];
//             window[c]++;

//             // 某种字符刚好满足要求
//             if (need.count(c) && window[c] == need[c])
//                 formed++;

//             // 当前窗口已经覆盖 t，尝试收缩
//             while (left <= right && formed == required)
//             {
//                 if (right - left + 1 < minLen)
//                 {
//                     minLen = right - left + 1;
//                     start = left;
//                 }

//                 char d = s[left];
//                 window[d]--;

//                 // 某种字符不再满足要求
//                 if (need.count(d) && window[d] < need[d])
//                     formed--;

//                 left++;
//             }

//             right++;
//         }

//         return minLen == INT_MAX ? "" : s.substr(start, minLen);
//     }
// };

// 学习labuladong再来一版
// 好像也没有办法避免这个formed变量的出现
// 已经写对7成了
// #include <string>
// #include <map>
// #include <vector>
// #include <climits>

// using namespace std;
// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         if (s.empty() || t.empty())
//             return "";
//         string ans = "";
//         int left = 0, right = 0;
//         map<char, int> window;
//         map<char, int> target;
//         int start = 0;
//         int match = 0;
//         int minlen = INT_MAX;

//         for (auto &x : t)
//             target[x]++;

//         while (right != s.size()) // 注意左闭右开的迭代器式窗口
//         {
//             if (match == target.size()) // left动
//             {
//                 char c = s[left];
//                 start = left;
//                 if (right - left < s.size())
//                     minlen = min(right - left,minlen) ;
//                 if (target.count(c))
//                 {
//                     window[c]--;
//                     if (window[c] < target[c])
//                         match--;
//                 }
//                 left++;

//             }
//             else // right动
//             {
//                 char c = s[right];
//                 if (target.count(c))
//                 {
//                     window[c]++;

//                     if (window[c] == target[c])
//                         match++;
//                 }
//                 right++;
//             }
//         }

//         return minlen == INT_MAX ? ans : s.substr(start, minlen);
//     }
// };

// 最后一次
#include <string>
#include <map>
#include <climits>

using namespace std;
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty()) return "";
        string ans = "";

        map<char, int> window;
        map<char, int> target;

        for (auto &x : t)
            target[x]++;

        int left=0, right=0, start = 0, minlen = INT_MAX, match = 0;

        while (right != s.size())
        {
            char c = s[right];
            if (target.count(c))
            {
                window[c]++;
                if (window[c] == target[c])
                    match++;
            }
            right++;

            while(match==target.size())
            {
               if (right - left < minlen)//这里是最后的错误
                {
                    minlen = right - left;
                    start = left;//start要跟minlen同步,所以不适合直接用一个min解决
                }
                char d=s[left];
                if(target.count(d))
                {
                    window[d]--;
                    if(window[d]<target[d])
                    match--;
                }
                
                left++;
            }
        }
        return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};