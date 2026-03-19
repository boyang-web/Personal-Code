/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
*/
#include <vector>
#include <stack>
#include <map>

using namespace std;

//出现了两个问题 收首先是0的逻辑整个没写
//其次是多个相同温度就没办法了
//解决方案是栈存储下标
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size());
        stack<int> stk;
        map<int, int> mp;
        for (int i = 0; i < temperatures.size(); i++)
            mp[temperatures[i]] = i;
        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!stk.empty() && temperatures[i] >= stk.top())
                stk.pop();
            ans[i]=mp[stk.top()]-i;
            stk.push(temperatures[i]);
        }

        return ans;
    }
};
//这个方案很巧妙
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        map<int, int> mp;
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty()&&temperatures[i]>=temperatures[stk.top()])
            stk.pop();
            ans[i]=stk.empty()?0:stk.top()-i;
            stk.push(i);
        }
        
        return ans;
    }
};