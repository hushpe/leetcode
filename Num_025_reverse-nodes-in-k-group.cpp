#include<iostream>

// https://leetcode-cn.com/problems/reverse-nodes-in-k-group

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k < 2) return head;

        int idx = 0;
        ListNode *last = head;
        while(idx < k) {
            if(last) {
                last = last->next;
                ++idx;
            } else {
                break;
            }
        }

        if(idx < k) return head;

        ListNode *newTail = head;
        ListNode *newHead = nullptr;
        idx = 0;
        while(idx < k) {
            ListNode *tmp = head;
            head = head->next;
            
            tmp->next = newHead;
            newHead = tmp;
    
            ++idx;
        }

        newTail->next = reverseKGroup(last, k);

        return newHead;
    }
};