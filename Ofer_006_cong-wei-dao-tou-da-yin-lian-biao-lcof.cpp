#include<iostream>
#include<stack>
#include<vector>
using namespace std;


// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        // std::vector<int> ans;
        // while(head != nullptr) {
        //     ans.emplace_back(head->val);
        //     head = head->next;
        // }
        // for(int left = 0, right = (int)ans.size()-1; left < right; ++left, --right){
        //     swap(ans[left], ans[right]);
        // }
        // return ans;

        int num = 0;
        std::stack<ListNode*> st;
        while(head != nullptr) {
            st.push(head);
            head = head->next;
            ++num;
        }

        std::vector<int> ans(num);
        int idx = 0;
        while(!st.empty()) {
            auto data = st.top();
            ans[idx++] = data->val;
            st.pop();
        }
        return ans;
    }
};