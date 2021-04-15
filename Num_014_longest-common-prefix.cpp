#include<iostream>
#include<vector>
#include<string>

using namespace std;

// https://leetcode-cn.com/problems/longest-common-prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs.back();

        bool flag = false;
        int len = 1;
        string first = strs.front();
        while(len <= first.size()) {
            for(int idx = 0; idx < strs.size() - 1; ++idx) {
                if(len > strs[idx].size() || len > strs[idx+1].size() || strs[idx][len-1] != strs[idx+1][len-1]) {
                    flag = true;
                    len = len -1;
                    break;
                }
            }
            if(flag) {
                break;
            } else {
                ++len;
            }
        }
        
        return first.substr(0, len);
    }
};