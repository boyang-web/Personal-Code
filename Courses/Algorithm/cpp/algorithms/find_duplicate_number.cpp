/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

示例 1：
输入：nums = [1,3,4,2,2]
输出：2
示例 2：
输入：nms = [3,1,3,4,2]
输出：3
示例 3 :
输入：nums = [3,3,3,3,3]
输出：3
*/
#include <vector>
using namespace std;
//构建一个链表逻辑模型，再用判环的方法做题
//注意需要自己完全模拟一遍流程
//这里用到了do while 注意语法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[fast];
            fast=nums[fast];
        }
        while(slow!=fast);
        int newp=0;
        while(newp!=slow)
        {
            slow=nums[slow];
            newp=nums[newp];
        }
        return newp;
    }
};