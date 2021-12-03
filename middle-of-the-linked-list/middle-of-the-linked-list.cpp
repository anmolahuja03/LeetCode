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
    ListNode* middleNode(ListNode* head) {
        /*
        ListNode *curr = head;
        int count_nodes = 0;
        int ans = 0;
        while(curr) {
            curr = curr->next;
            count_nodes++;
        }
        curr = head;
        while(ans < count_nodes/2) {
            curr = curr->next;
            ans++;
        }
        return curr;
        */
        
        
        ListNode *slow = head; 
        ListNode *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};