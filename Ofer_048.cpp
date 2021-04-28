#include<iostream>
#include<string>
#include<unordered_map>

//https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;

        int start = -1, end = 0, ans = 0;
        std::unordered_map<char, int> um;
        for(int idx = 0; idx < s.size(); ++idx) {
            end = idx;
            if(um.find(s[idx]) == um.end() || um[s[idx]] < start) {
                if(start == -1) {
                    ans = idx + 1;
                } else if(ans < end - start + 1) {
                    ans = end - start + 1;
                }
            } else {
                start = um[s[idx]] + 1;
            }
            um[s[idx]] = idx;
        }

        return ans;
    }
};

int main(){
    string s = "pwwkew";

    Solution sl;
    cout << sl.lengthOfLongestSubstring(s) << endl;

    return 0;
}