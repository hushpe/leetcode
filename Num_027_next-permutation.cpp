#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// https://leetcode-cn.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int loc = -1;
        for(int idx = nums.size()-1; idx > 0; --idx) {
            if(nums[idx] > nums[idx-1]) {
                loc = idx;
                break;
            }
        }

        if(loc == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        int match = loc;
        for(int idx = loc+1; idx < nums.size(); ++idx) {
            if(nums[idx] > nums[loc-1] && nums[idx] < nums[match]) {
                match = idx;
            }
        }

        swap(nums[loc-1], nums[match]);

        sort(nums.begin()+loc, nums.end());
    }
};