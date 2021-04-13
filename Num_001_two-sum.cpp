#include<iostream>
#include<vector>
#include<unordered_map>

// https://leetcode-cn.com/problems/two-sum
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> diff;
        for(int idx = 0; idx < nums.size(); ++idx) {
            if(diff.find(nums[idx]) != diff.end()) {
                return std::vector<int>{diff[nums.at(idx)], idx};
            } else {
                diff[target-nums[idx]] = idx;
            }
        }

        return std::vector<int>();
    } 
};


int main(){
    std::vector<int> nums{2,7,11,15};

    Solution sl;
    auto ans = sl.twoSum(nums, 9);
    std::cout << ans[0] << "  " << ans[1] << std::endl;

    return 0;
}
