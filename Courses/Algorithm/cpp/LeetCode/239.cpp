/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。



示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]

*/
// 单调队列的方法复刻一下
//复刻失败
// #include <vector>
// #include <deque>

// using namespace std;
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         if (k > nums.size() || nums.empty())
//             return {};

//         int left = 0, right = k;
//         deque<int> q;
//         vector<int> ans;
//         for (int i = 0; i < k; i++) // 初始化
//         {
//             int n = nums[i];
//             while (!q.empty() && n > q.back())
//                 q.pop_back();

//             q.push_back(n);
//         }
//         ans.push_back(q.front());
//         q.pop_front();
//         while (right < nums.size())
//         {
//             int n = nums[right];
//             while (!q.empty() && n > q.back())
//                 q.pop_back();
//             q.push_back(n);
//             right++;
//             ans.push_back(q.front());
//             q.pop_front();
//         }
//         return ans;
//     }
// };

//ai版本
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty() || k > nums.size())
            return {};

        deque<int> q;   // 存下标//这就跟单调栈的题很相似了
        vector<int> ans;

        for (int right = 0; right < nums.size(); right++)
        {
            // 1. 维护单调递减队列
            while (!q.empty() && nums[right] >= nums[q.back()])
                q.pop_back();
            q.push_back(right);

            // 2. 删除滑出窗口的元素
            if (q.front() <= right - k)
                q.pop_front();

            // 3. 窗口形成后开始记录答案
            if (right >= k - 1)
                ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};