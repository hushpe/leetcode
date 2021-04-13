#include<iostream>
#include<string>
#include<unordered_map>

//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;

        std::unordered_map<char, int> ch_idx;
        int left = -1, max = 0, len = 0;
        for(int idx = 0; idx < s.size(); ++idx) {
            if(ch_idx.find(s[idx]) == ch_idx.end()) {
                len++;
            } else {
                if(ch_idx[s[idx]] < left) {
                    len++;  
                } else {
                    max = std::max(len, max);
                    left = ch_idx[s[idx]] + 1;
                    len = idx - left + 1;
                }  
            }
            ch_idx[s[idx]] = idx;
        }
        return std::max(len, max);
    }
};