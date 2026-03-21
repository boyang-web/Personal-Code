/*
给定一个二进制数组 nums 和一个整数 k，假设最多可以翻转 k 个 0 ，则返回执行操作后 数组中连续 1 的最大个数 。

 

示例 1：

输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
*/

//合法窗口是正好有三个0，多了left++,少了right++
#include<vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;//最大ans
        int window=0;//当前合法窗口长度
        int left=0,right=0;
        int znum=0;
        while(right<nums.size())
        {
            int inter=nums[right];
            if(inter==0)
            znum++;
            
            window++;
           
            right++;
           
            
            while(znum>k&&left<right)
            {
                
                int outer=nums[left];
                if(outer==0)
                znum--;
                window--;
                left++;
            }
            ans=max(ans,window);//这个位置是肯定合法的
        }

        return ans;
    }
};