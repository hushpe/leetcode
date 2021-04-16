#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int loc = 0;
        for(int idx = nums.size()-1; idx > 0; --idx) {
            if(nums[idx] > nums[idx-1]) {
                swap(nums[idx], nums[idx-1]);
                loc = idx;
                break;
            }
        }
        cout << loc << endl;
        sort(nums.begin()+loc, nums.end());
    }
};

int main(){
    vector<int> nums{1,2,3};
    Solution sl;
    sl.nextPermutation(nums);
    for(auto ele: nums){
        cout << ele << " ";
    }
    cout << endl;
}