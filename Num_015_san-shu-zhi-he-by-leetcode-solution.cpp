#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

//https://leetcode-cn.com/problems/3sum/solution/san-shu-zhi-he-by-leetcode-solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return std::vector<std::vector<int>>();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int idx = 0; idx < (int)nums.size(); ++idx) {
            if(idx > 0 && nums[idx] == nums[idx-1]) {
                continue;
            }
            auto tmp = twoSum(nums, -nums[idx], idx+1);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        
        return ans;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int target, int ignore) {
        unordered_set<int> sum;
        vector<vector<int>> ans;
        int left = ignore, right = nums.size()-1;

        while(left < right) {
            if(nums[left] + nums[right] < target) {
                while(left < right && nums[left] == nums[left+1]){
                    ++left;
                }
                ++left;
            } else if(nums[left] + nums[right] > target) {
                while(left < right && nums[right] == nums[right-1]){
                    --right;
                }
                --right;
            } else {
                ans.emplace_back(std::vector<int>{-target, nums[left],nums[right]});
                while(left < right && nums[right] == nums[right-1]){
                    --right;
                }
                while(left < right && nums[left] == nums[left+1]){
                    ++left;
                }
                ++left;
                --right;
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum2(vector<int>& nums) {
        if(nums.size() < 3) return std::vector<std::vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int idx = 0; idx < nums.size()-1; ++idx) {
            auto tmp = twoSum2(nums, -nums[idx], idx);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
            while(idx < nums.size()-1 && nums[idx] == nums[idx+1]) {
                idx++;
            }
        }
        
        return ans;
    }

    vector<vector<int>> twoSum2(vector<int>& nums, int target, int ignore) {
        unordered_set<int> sum;
        vector<vector<int>> ans;
        for(int idx = ignore+1; idx < nums.size(); ++idx) {
            if(sum.find(nums[idx]) != sum.end()) {
                ans.emplace_back(std::vector<int>{-target, target-nums[idx],nums[idx]});
                while(idx < nums.size()-1 && nums[idx] == nums[idx+1]) {
                    idx++;
                }
            } else {
                sum.insert(target-nums[idx]);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{-1,0,1,2,-1,-4};
    Solution sl;
    auto ans = sl.threeSum(nums);
    for(auto ele: ans) {
        for(auto val: ele) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}