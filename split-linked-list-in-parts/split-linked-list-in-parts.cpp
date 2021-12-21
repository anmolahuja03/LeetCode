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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, NULL);
        ListNode* curr = head, *prev = NULL;
        int node_count = 0;
        while(curr != NULL) {
            node_count++;
            curr = curr->next;
        }
        int every_part = node_count / k;
        int extra = node_count % k;
        curr = head;
        int cnt = 0;
        while(curr != NULL && cnt < k) {
            res[cnt] = curr;
            int temp = 1;
            while(temp <= (every_part + (extra > 0))) {
                prev = curr;
                curr = curr->next;
                temp++;
            }
            if(extra > 0)
                extra--;
            prev->next = NULL;
            cnt++;
        }
        return res;
    }
};