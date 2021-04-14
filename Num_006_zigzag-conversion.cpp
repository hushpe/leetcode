#include<iostream>
#include<vector>
#include<string>

using namespace std;

//https://leetcode-cn.com/problems/zigzag-conversion
class Solution {
public:
    string convert(string s, int numRows) {
        std::string ans;
        std::vector<std::string> v_ans(numRows);
        
        int loc = 0;
        for(int idx = 0; idx < s.size(); ++idx) {
            v_ans[loc] += s[idx];
            int num = idx % (numRows*2 - 2) + 1;

            if(num > numRows -1) {
                loc--;
            } else {
                loc++;
            }
        }

        for(auto ele: v_ans) {
            ans += ele;
        }

        return ans;
    }
};

