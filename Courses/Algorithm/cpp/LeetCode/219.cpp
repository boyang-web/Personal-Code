/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

示例 1：

输入：nums = [1,2,3,1], k = 3
输出：true
*/
// 给定窗口长度，寻找是否存在相同元素

//完整自己做出来的 士气+1
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {

        map<int, int> window;

        int left = 0, right = 0;

        // 初始化窗口
        for(int i=0;i<k&&i<nums.size();i++)
        {
            int n=nums[right];
            window[n]++;
            right++;
            if(window[n]>1)
            return true;
        }
        while(right<nums.size())
        {
            int n=nums[right];
            window[n]++;
            right++;
            
            if(window[n]>1)
            return true;
            int m=nums[left];
            window[m]--;
            left++;
        }
        return false;

    }
};