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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        int cnt_nodes = 0;
        ListNode* curr = head;
        while(curr != NULL) {
            cnt_nodes++;
            curr = curr->next;
        }
        int temp = k % cnt_nodes;
        int len = cnt_nodes - temp;
        if(len == cnt_nodes)
            return head;
        curr = head;
        int num = 1;
        while(num < len) {
            num++;
            curr = curr->next;
        }
        ListNode* tmp1 = curr->next;
        curr->next = NULL;
        ListNode* curr1 = tmp1;
        while(curr1->next != NULL) {
            curr1 = curr1->next;
        }
        curr1->next = head;
        return tmp1;
    }
};