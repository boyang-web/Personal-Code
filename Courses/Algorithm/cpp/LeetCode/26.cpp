/*
要点：
返回的是序列的长度而不是下标，所以要加一
*/

#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int fast = 1, slow = 0;
        while (fast != nums.size()) {
            if (nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};