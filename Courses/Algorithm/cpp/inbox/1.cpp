/*
给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。
示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]

提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
*/

// 哈希表做法(自己写的)
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> temp;
        for (int i = 0; i < nums.size(); i++)
            temp[target - nums[i]] = i;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (temp.count(nums[i]) && i != temp[nums[i]])
            {
                ans.push_back(i);
                ans.push_back(temp[nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};

// 哈希表做法（leetcode题解）
/*
学习迭代器写法
利用find写出来了逻辑上只用遍历一次的写法
这种直接返回的方式也比较优秀
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = temp.find(target - nums[i]);
            if (it != temp.end())
                return {i, it->second};
            temp[nums[i]] = i;
        }
        return {};
    }
};

// 双指针做法
// 注意返回下标好像有点做不到 但是167题可以完成
// 基于排序后两数之和的单调性进行遍历
// 注意sort排序默认是less升序
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {};
        // 还要存储原始下标
        map<int, int> ori;
        for (int i = 0; i < nums.size(); i++)
            ori[nums[i]] = i;

        sort(nums.begin(), nums.end());
        int front = 0, back = nums.size() - 1;
        while (front != back)
        {
            if (nums[front] + nums[back] < target)
                front++;
            else if (nums[front] + nums[back] > target)
                back--;
            else
                return {ori[nums[front]], ori[nums[back]]}; // 无法处理用例3 [3 , 3]
        }
        return {};
    }
};