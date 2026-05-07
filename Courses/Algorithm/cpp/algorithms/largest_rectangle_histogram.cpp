/*
84. 柱状图中最大的矩形
困难
相关标签
premium lock icon
相关企业
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

示例 1:

输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
示例 2：
*/
// #include <vector>
// #include <stack>

// using namespace std;

// 近期最后一题了，可喜可贺
// 不用单调栈还是TLE 了
// class Solution
// {
// public:
//     int largestRectangleArea(vector<int> &heights)
//     {
//         int ans = 0;
//         // 分别找到左右第一个更小的元素的下标
//         int right = 0, left = 0;
//         for (int i = 0; i < heights.size(); i++)
//         {
//             right = i, left = i;
//             for (int j = i; j < heights.size(); j++)
//             {

//                 if (heights[j] < heights[i])
//                 {
//                     right = j;
//                     break;
//                 }
//                 right = j+1;
//             }
//             for (int j = i; j >= 0; j--)
//             {

//                 if (heights[j] < heights[i])
//                 {
//                     left = j;
//                     break;
//                 }
//                 left = j-1;
//             }
//             ans = max(ans, heights[i] * (right - left - 1));
//         }
//         return ans;
//     }
// };
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n=heights.size();
        vector<int> leftv(n),rightv(n);
        stack<int> stkleft,stkright;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                leftv[i]=-1;
                stkleft.push(i);//存下标
                continue;
            }
            while(!stkleft.empty()&&heights[i]<=heights[stkleft.top()])
            {
                stkleft.pop();
            }
            leftv[i]=stkleft.empty()?-1:stkleft.top();
            stkleft.push(i);
        }
         for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                rightv[i]=n;
                stkright.push(i);//存下标
                continue;
            }
            while(!stkright.empty()&&heights[i]<=heights[stkright.top()])
            {
                stkright.pop();
            }
            rightv[i]=stkright.empty()?n:stkright.top();
            stkright.push(i);
        }
        //计算面积
        for(int i=0;i<n;i++)
        {
            int temp=heights[i]*(rightv[i]-leftv[i]-1);
            ans=max(ans,temp);

        }
        return ans;

    }
};