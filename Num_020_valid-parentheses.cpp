#include<iostream>
#include<unordered_map>
#include<stack>

using namespace std;

// https://leetcode-cn.com/problems/valid-parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        unordered_map<char, char> pairs{ {')', '('}, {']', '['}, {'}', '{'} };
        for(char ch: s) {
            if(pairs.count(ch)) {
                if(sc.empty()) return false;
                if(sc.top() != pairs[ch]) return false;
                sc.pop();
            } else {
                sc.push(ch);
            }
        }

        return sc.empty();
    }
};