#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

// https://leetcode-cn.com/problems/3sum-closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());

        int ans = INT32_MAX;
        for(int idx = 0; idx < (int)nums.size(); ++idx) {
            auto num = twoSum(nums, target-nums[idx], idx+1);
            if(0 == num) {
                return target;
            }
            
            if(abs(num) < abs(ans)){
                ans = num;
            }
        }
        return target - ans;
    }

    int twoSum(vector<int>& nums, int target, int ignore) {
        int ans = INT32_MAX;
        int left = ignore, right = nums.size()-1;

        while(left < right) {
            int tmp = target - (nums[left] + nums[right]);
            if(abs(tmp) < abs(ans)) {
                ans = tmp;
            }
            if(tmp < 0) {
                --right;
            } else if(tmp > 0) {
                ++left;
            } else {
                return 0;
            }
        }
       return ans;
    }
};

int main() {
    vector<int> nums{0,2,1,-3};
    Solution sl;
    auto ans = sl.threeSumClosest(nums, 1);
    cout << ans << endl;
    
    return 0;
}