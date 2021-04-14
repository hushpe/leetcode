#include<iostream>
#include<math.h>
#include<limits.h>

using namespace std;

//https://leetcode-cn.com/problems/palindrome-number
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;

        int back = 0;
        while(x > back) {
            back = 10 * back + x % 10;
            x = x / 10;
            if(back == 0) return false;
            if(back == x ||(x >= 10 && x / 10 == back)) return true;
        }

        return false;
    }
};

int main(){
    int x = 1000021;
    Solution sl;
    cout << sl.isPalindrome(x) << endl;
}