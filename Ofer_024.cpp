#include<iostream>

using namespace std;

//https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }
    ListNode* reverseList1(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *left = head;
        head = head->next;
        left->next = nullptr;
        
        while(head->next != nullptr) {
            ListNode *tmp = head->next;
            head->next = left;
            left = head;
            head = tmp;
        }

        head->next = left;
        return head;
    }
};