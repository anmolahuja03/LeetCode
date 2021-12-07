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
    // Approach : Reverse the given linked list,
    // traverse & convert binary into decimal
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *temp;
        
        while(curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    int getDecimalValue(ListNode* head) {
        ListNode *tmp = reverse(head);
        int ans = 0, ptr = 0;
        
        while(tmp) {
            ans = ans + pow(2, ptr) * (tmp->val);
            ptr++;
            tmp = tmp->next;
        }
        return ans;
    }
};