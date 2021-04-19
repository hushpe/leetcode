#include<iostream>
#include<vector>

using namespace std;

// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(nums[0] == target) {
                return std::vector<int>{0, 0};
            }
        }
        int left = 0;
        int right = nums.size() - 1;
        
        int ans = -1;
        while(left <= right) {
            int mid = (left+right)/2;
            if(nums[mid] == target) {
                ans = mid;
                break;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if(ans == -1) {
            return std::vector<int>{-1, -1};
        }

        left = ans;
        right = ans;

        while(left > 0 && nums[left-1] == target) {
            --left;
        }
        while(right < nums.size()-1 && nums[right+1] == target) {
            ++right;
        }
        return std::vector<int>{left, right};
    }
};