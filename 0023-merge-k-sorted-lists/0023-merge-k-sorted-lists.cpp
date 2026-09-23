class Solution {
    struct compare {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;


        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        
        ListNode dummy(0);
        ListNode* tail = &dummy;


        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();


            tail->next = smallest;
            tail = tail->next;


            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};