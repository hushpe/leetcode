#include<iostream>
#include<string>
using namespace std;

//https://leetcode-cn.com/problems/longest-palindromic-substring
class Solution {
public:
    string longestPalindrome(string s) {
        std::string ans;

        for(int idx = 0; idx < s.size(); ++idx) {
            auto s1 = longest(s, idx, idx);
            auto s2 = longest(s, idx, idx+1);
            auto lg = (s1.size()>s2.size()? s1: s2);
            if(lg.size() > ans.size()) {
                ans = lg;
            }
        }

        return ans;
    }

    string longest(string s, int left, int right) {
        const int min = 0, max = s.size()-1;
        do {
            if(left < min || right > max) {
                return s.substr(left+1, right-left-1);
            }

            if(s[left] == s[right]) {
                left--;
                right++;
            } else {
                return s.substr(left+1, right-left-1);
            }
        }while(true);
    }
};

int main(){
    std::string nums = "babad";

    Solution sl;
    auto ans = sl.longestPalindrome(nums);
    std::cout << ans << std::endl;

    return 0;
}
