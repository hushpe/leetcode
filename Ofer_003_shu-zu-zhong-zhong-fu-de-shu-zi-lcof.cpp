#include<iostream>
#include<vector>

using namespace std;

// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int idx = 0; idx < nums.size();) {
            if(nums[idx] == idx) {
                ++idx;
            } else {
                if(nums[idx] == nums[nums.at(idx)]) {
                    return nums[idx];
                }
                swap(nums[idx], nums[nums.at(idx)]);
            }
        }
        return -1;
    }
};