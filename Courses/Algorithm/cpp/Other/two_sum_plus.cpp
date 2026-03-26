// nums 中可能有多对儿元素之和都等于 target，
// 请你的算法返回所有和为 target 的元素对儿，其中不能出现重复。

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

void writefile()
{
    ofstream fout("tempfile/twoNumPlus.txt");
    fout << "1 3 2 4 1 5 2 6 3 7 1";
}

int main()
{
    writefile();
    int target = 7;
    ifstream fin("tempfile/twoNumPlus.txt");
    string token;
    vector<int> nums;
    while (fin >> token)
        nums.push_back(stoi(token));
    vector<pair<int, int>> ans;
    // 核心逻辑
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum > target)
        {
            int temp = nums[right];
            while (right > left && temp == nums[right])
                right--;
        }
        else if (sum < target)
        {
            int temp = nums[left];
            while (right > left && temp == nums[left])
                left++;
        }
        else
        {
            ans.push_back({nums[left],nums[right]});
            int tempLeft = nums[left];
            int tempRight = nums[right];

            while (left < right && nums[left] == tempLeft)//注意这里不能忘了
                left++;
            while (left < right && nums[right] == tempRight)
                right--;
        }
    }

    // 输出
    for (auto x : ans)
    {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}