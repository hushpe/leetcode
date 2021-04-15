#include<iostream>

//https://leetcode-cn.com/problems/swap-nodes-in-pairs/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *last = head->next->next;
        ListNode *newHead = head->next;
        newHead->next = head;
        newHead->next->next = swapPairs(last);
        return newHead;
    }
};

