/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr, *next;
        
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* fun(ListNode* l1, ListNode* l2) {
        int digit, carry = 0;
        ListNode* res = NULL;
        ListNode* tmp = new ListNode(-1);
        res = tmp; 
        
        while(l1 || l2) {
            digit = carry;
            if(l1) {
                digit += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                digit += l2->val;
                l2 = l2->next;
            }
            carry = digit / 10;
            digit = digit % 10;
            tmp->next = new ListNode(digit);
            tmp = tmp->next;
        }
        if(carry) {
            tmp->next = new ListNode(carry);
            tmp = tmp->next;
        }
        return res->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = reverse(l1);
        ListNode* h2 = reverse(l2);
        ListNode* res = fun(h1, h2);
        return reverse(res);
    }
};