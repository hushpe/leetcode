#include<iostream>

// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pHead = new ListNode();
        pHead->next = head;

        ListNode* tHead = pHead;
        int end = 0;
        while(end < n && tHead != nullptr) {
            tHead = tHead->next;
            ++end;
        }
        if(end != n) {
            delete pHead;
            return head;
        }

        ListNode* p1 = pHead;
        while(tHead->next != nullptr) {
            p1 = p1->next;
            tHead = tHead->next;
        }

        p1->next = p1->next->next;

        ListNode *ans = pHead->next;
        delete pHead;
        return ans;
    }
};