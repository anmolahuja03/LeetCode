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
    ListNode* mid(ListNode *head) {
        ListNode* slow = head; 
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode *head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode* mid_node = mid(head);
        ListNode* h1 = head;
        ListNode* h2 = mid_node->next;
        mid_node->next = NULL;
        h2 = reverse(h2);
        
        while(h2 && h1) {
            ListNode *tmp1 = h1->next;
            ListNode *tmp2 = h2->next;
            h1->next = h2;
            h2->next = tmp1;
            h1 = tmp1;
            h2 = tmp2;
        }
    }
};