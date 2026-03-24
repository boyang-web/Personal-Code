/*

给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，
使得剩下的数字最小。请你以字符串形式返回这个最小的数字。


示例 1 ：

输入：num = "1432219", k = 3
输出："1219"
解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
示例 2 ：*/

#include <string>
#include <stack>
#include <algorithm>

// 大体思路对了，细节错了不少，重写
//  using namespace std;
//  class Solution
//  {
//  public:
//      string removeKdigits(string num, int k)
//      {
//          stack<int> stk;
//          int times = k;
//          for (char x : num)
//          {
//              while (!stk.empty() && stk.top() > x - '0'&&k>=1)
//              {
//                  stk.pop();
//                  k--;
//              }
//              if ((stk.empty() && x - '0' != 0) || (!stk.empty()))
//                  stk.push(x - '0');

//         }

//         string ans = "";
//         while (!stk.empty())
//         {
//             ans += to_string(stk.top());
//             stk.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans == "" ? "0" : ans;
//     }
// };

using namespace std;
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k >= num.size())
            return "0";
        int times = k;
        string ans;
        for (char c : num)
        {
            if (ans.empty()&&c!='0')
            {
                ans.push_back(c);
            }
            else//非空情形且           
            {
                
                while(!ans.empty()&&ans.back()>c&&k!=0)
                {
                    ans.pop_back();
                    k--;
                }
                if(c!='0'||!ans.empty())
                ans.push_back(c);

            }
        }
        while(k!=0&&!ans.empty())//很多地方都要判空
        {
            ans.pop_back();
            k--;
        }
        return ans==""?"0":ans;
    }
};