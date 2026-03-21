/*
给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。

如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。



示例 1：

输入：nums = [1,1,4,2,3], x = 5
输出：2
解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
示例 2：

输入：nums = [5,6,7,8,9], x = 4
输出：-1
示例 3：

输入：nums = [3,2,20,1,1,3], x = 10
输出：5
解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
*/

// 思路应该是初始化只走一边直到和太大，再滑动直到另一边和太大
// 临门一脚，实则是转化为中间窗口和为sum-x即可
// #include <vector>
// #include <iostream>
// #include <cctype>
// using namespace std;
// class Solution
// {
// public:
//     int minOperations(vector<int> &nums, int x)
//     {
//         int ans = INT_MAX;
//         int sum = 0;
//         int left = -1, right = nums.size() - 1;
//         while (sum < x && left < right) // 初始化
//         {
//             left++;
//             sum += nums[left];
//             if (sum == x)
//                 ans = min(ans, left + 1);
//         }
//         while (left >= 0)
//         {
//             if (sum > x)
//             {
//                 sum -= nums[left];
//                 left--;
//             }
//             else if (sum < x)
//             {
//                 sum += nums[right];
//                 right--;
//             }
//             else
//             {
//                 ans = min(ans, int(left + nums.size() - right));
//                 sum -= nums[left];
//                 left--;
//             }
//         }
//         return ans == INT_MAX ? -1 : ans;
//     }
// };
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0)//这两个边界情况需要带入思考一下
            return -1;
        if (target == 0)
            return nums.size();
        int left = 0, right = 0;
        int ans = INT_MAX;
        int sum = 0;
        while (right < nums.size())
        {
            sum += nums[right];
            right++;
            if (sum == target)
                ans = min(ans, int(nums.size() - (right - left)));
            while (sum > target)
            {
                sum -= nums[left];
                left++;
                if (sum == target)
                    ans = min(ans, int(nums.size() - (right - left)));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};