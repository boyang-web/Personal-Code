/*
输入: nums = [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。*/

// 数组翻倍可以做，研究一下循环数组技巧来扩倍
// 循环时借用取模循环两次即可
#include <stack>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        stack<int> stk;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int j = i % n;
            while (!stk.empty() && nums[j] >= stk.top())
                stk.pop();
            res[j] = stk.empty() ? -1 : stk.top();
            stk.push(nums[j]);
        }

        return res;
    }
};