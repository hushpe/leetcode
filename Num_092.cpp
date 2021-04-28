#include<iostream>

using namespace std;
// https://leetcode-cn.com/problems/reverse-linked-list-ii
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left > right || head == nullptr) return head;
        if(1 == left) return reverse(head, right-left+1);

        int idx = 2;
        ListNode *preHead = head;
        ListNode *curHead = head->next;
        while(preHead && idx < left) {
            preHead = preHead->next;
            curHead = curHead->next;
            idx++;
        } 

        if(idx != left) return head;

        preHead->next = reverse(curHead, right-left+1);
        return head;
    }

    ListNode* reverse(ListNode* head, int len) {
        if(1 == len || head == nullptr) return head;

        ListNode *lastHead = head;
        ListNode *preHead = head;
        ListNode *curHead = head->next;
        int idx = 1;
        while(curHead && idx < len) {
            ListNode *tmp = curHead->next;
            curHead->next = preHead;
            preHead = curHead;
            curHead = tmp;
            idx++;
        } 
        if(idx != len) {
            lastHead->next = nullptr;
        } else {
            lastHead->next = curHead;
        }

        return preHead;
    }
};