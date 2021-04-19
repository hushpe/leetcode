#include<iostream>
#include<vector>
using namespace std;

// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;

        int n = matrix.size(), m = matrix[0].size();

        for(int ii = 0, jj = m-1; ii < n && jj >= 0;) {
            if(matrix[ii][jj] == target) {
                return true;
            } else if(matrix[ii][jj] < target) {
                ++ii;
            } else {
                --jj;
            }
        }

        return false;
    }
};