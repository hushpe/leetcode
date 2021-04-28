#include<iostream>

using namespace std;

// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof

const int BigPrimeNum = 1e9+7;      // 防止越界, 质数, 且2数之和小于整数
class Solution {
public:
    int fib(int n) {
        if(0 == n) return 0;
        if(1 == n) return 1;

        int a = 0, b = 1;
        for(int idx = 2; idx <= n; ++idx) {
            a = (a + b) % BigPrimeNum;
            swap(a, b);
        }
        return b;
    }
};

int main() {
    Solution sl;
    cout << sl.fib(3) << endl;
}