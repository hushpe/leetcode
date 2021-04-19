#include<iostream>
#include<vector>
#include<string>

using namespace std;

//https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
class Solution {
public:
    string replaceSpace(string s) {
        int num_space = 0;
        for(char ch: s) {
            if(ch == ' ') ++num_space;
        }

        int len = s.size()-1;
        s.resize(s.size()+num_space*2);

        for(int last = s.size()-1; len >= 0; --len) {
            if(s[len] == ' '){
                s[last--] = '0';
                s[last--] = '2';
                s[last--] = '%';
            } else {
                s[last--] = s[len];
            }
        }

        return s;
    }
};

int main(){
    string s = "12345";
    cout << s << "  "  << s.size() << endl;


    s.resize(3);
    cout << s << "  "  << s.size() << endl;


    s.resize(8, 'a');
    cout << s << "  "  << s.size() << endl;

    s.resize(10, 'b');
    cout << s << "  "  << s.size() << endl;

    
    std::vector<int> myvector = {10,20,30};

    auto it = myvector.emplace ( myvector.end(), 100 );

    cout << *it << endl;
    for(auto ele: myvector) {
        cout << ele << ' ';
    }
    cout << endl;

}