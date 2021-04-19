#include<iostream>
#include<vector>

using namespace std;

// https://leetcode-cn.com/problems/first-missing-positive
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;

        for(int idx = 0; idx < nums.size();) {
            if(nums[idx] == idx+1 || nums[idx] <= 0 || nums[idx] > nums.size()) {
                ++idx;
            } else if(nums[idx] < idx+1){
                nums[nums[idx]-1] = nums[idx];
                ++idx;
            } else {
                if(nums[idx] == nums[nums[idx]-1]) {
                    ++idx;
                } else {
                    swap(nums[idx], nums[nums[idx]-1]);
                }  
            }
        }

        for(int idx = 0; idx < nums.size(); ++idx) {
            if(nums[idx] != idx+1) {
                return idx+1;
            }
        }

        return nums.size()+1;
    }
};