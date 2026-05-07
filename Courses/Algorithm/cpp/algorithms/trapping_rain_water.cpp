/*给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
计算按此排列的柱子，下雨之后能接多少雨水。



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，
在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 */

/*有三种思路
首先是找两边最大的柱子再取最小值，得到这一竖条能存多少水
其次是逐层递降，一层一层判定能装多少水
还有就是单调栈：保持单调递减，有一个更大的元素了就逐个出栈然后计算水 */
#include <vector>

using namespace std;
// 思路1
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int n = height.size();
//         vector<int> leftmax(n), rightmax(n);
//         for (int i = 0; i < n; i++)
//         {
//             if (i == 0)
//             {
//                 leftmax[i] = 0;
//                 continue;
//             }
//             leftmax[i] = max(leftmax[i - 1], height[i - 1]);
//         }
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (i == n - 1)
//             {
//                 rightmax[i] = 0;
//                 continue;
//             }
//             rightmax[i] = max(rightmax[i + 1], height[i + 1]);
//         }
//         // 计算水量
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             // int temp=min(leftmax[i], rightmax[i]);//这样写是错的，可能会减出负数来
//             // ans += temp==0?0:temp-height[i];
//             ans += max(0, min(leftmax[i], rightmax[i]) - height[i]);
//         }
//         return ans;
//     }
// };

// 思路2肉眼可见的麻烦
// 思路3只用遍历一遍，应该是最优的那一批了
#include <stack>
#include<cmath>
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> stk;//还是要存下标
        int ans=0;
        int n=height.size();
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(i);
                continue;
            }
            while(!stk.empty()&&height[stk.top()]<=height[i])
            {
                // ans+=i-stk.top()-1;这里的处理思路想错了
                // stk.pop();
                int bottom=height[stk.top()];//这里的处理思路非常巧妙
                stk.pop();
                if (stk.empty()) break;
                ans+=(i-stk.top()-1)*(min(height[stk.top()],height[i])-bottom);

        
            }
            stk.push(i);
        }
        return ans;
    }
};