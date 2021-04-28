#include<iostream>
#include<limits>
using namespace std;

// https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1) return x;
        if(x == -1) return (1 == (n & 0x1))? -1: 1;

        if(n < 0) {
            if(std::numeric_limits<int>::min() == n) {
                x = 1 / (x*x);
                n = -(n/2);
            } else {
                x = 1/x;
                n = -n;
            }
        }

        double ans = 1.0;
        while(n) {
            if(n & 0x1) {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }

        return ans;
    }
};

int main(){
    int n = 10;
    Solution sl;
    cout << sl.myPow(2, n) << endl;

    cout << std::numeric_limits<int>::min() << endl;
    return 0;
}