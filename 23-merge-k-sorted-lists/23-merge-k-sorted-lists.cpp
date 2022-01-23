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
    struct cmp {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
       
        for(auto x : lists) {
            if(x)
                pq.push(x);
        }
        ListNode* head = nullptr;
        ListNode* tail = head;
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if(head == nullptr) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = tail->next;
            }
            if(temp->next)
                pq.push(temp->next);
        }
        return head;
    }
};