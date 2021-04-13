
 #include<iostream>

// https://leetcode-cn.com/problems/add-two-numbers
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = nullptr, *tail = nullptr;

        while(l1 != nullptr || l2 != nullptr) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            if(tail) {
                tail->next = new ListNode(sum);
                tail = tail->next;
            } else {
                head = new ListNode(sum);
                tail = head;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry != 0) {
            tail->next = new ListNode(carry);
        }
    
        return head;
    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        int carry = 0;
        int sum = 0;
        ListNode* ans = l1;
        ListNode* last;
        while(l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            if(sum > 9) {
                carry = sum / 10;
                sum = sum % 10;
            } else {
                carry = 0;
            }

            l1->val = sum;
            last = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 != nullptr) {
            while(l1 != nullptr) {
                sum = l1->val + carry;
                if(sum > 9) {
                    carry = sum / 10;
                    sum = sum % 10;
                } else {
                    carry = 0;
                }
                l1->val = sum;
                last = l1;
                l1 = l1->next;
            }
        } else if(l2 != nullptr) {
            last->next = l2;
            while(l2 != nullptr) {
                sum = l2->val + carry;
                if(sum > 9) {
                    carry = sum / 10;
                    sum = sum % 10;
                } else {
                    carry = 0;
                }
                l2->val = sum;
                last = l2;
                l2 = l2->next;
            }
        } 

        if(carry != 0) {
            ListNode* tail = new ListNode(carry);
            last->next = tail;
        }
    
        return ans;
    }
};