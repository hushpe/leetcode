#include<iostream>
#include<vector>

using namespace std;

// https://leetcode-cn.com/problems/combination-sum
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        for(auto ite = candidates.begin(); ite != candidates.end(); ++ite) {
            if(*ite > target) {
                break;
            } else if(*ite == target){
                ans.push_back(std::vector<int>{*ite});
                break;
            } else {
                std::vector<int> vt(ite, candidates.end());
                auto vt = combinationSum(vt, target - *ite);
                for(vector<int> xx: vt){
                    xx.insert(xx.begin(), *ite);
                    ans.emplace_back(xx);
                }
            }
        }
        return ans;
    }
};