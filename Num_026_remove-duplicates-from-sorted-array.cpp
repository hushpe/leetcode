#include<iostream>
#include<vector>

using namespace std;

// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int loc = 0, right = 1;
        while(right < nums.size()) {
            if(nums[right] != nums[right-1]) {
                ++loc;
                nums[loc] = nums[right];
            }
            ++right;
        }

        return loc+1;
    }
};