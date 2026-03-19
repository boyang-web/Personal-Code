/*
输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
输出：[-1,3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。*/
#include <stack>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> nextele;
        stack<int> stk;
        vector<int> ans(nums1.size());//注意vector尽量一开始就初始化
        // 单调栈遍历
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top() <= nums2[i])
                stk.pop();
            nextele[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
            ans[i] = nextele[nums1[i]];
        return ans;
    }
};