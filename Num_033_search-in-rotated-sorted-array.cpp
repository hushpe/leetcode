#include<iostream>
#include<vector>

// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        if(nums.size() == 1) return (target == nums[0])? 0: -1;

        int left = 0, right = nums.size()-1;
        
        while(left <= right) {
            int mid = (right+left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[0] <= nums[mid]){
                //左正序，右旋转
                if(target >= nums[0] && target < nums[mid] ) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }    
            } else {
                //右正序，左旋转
                if(target > nums[mid] && target <= nums[nums.size()-1]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            } 
        }
        return -1;
    } 
};