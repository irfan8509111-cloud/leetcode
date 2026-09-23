class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            
            ListNode* kth = getKth(groupPrev, k);
            if (kth == nullptr) {
                break; 
            }
            
            ListNode* groupNext = kth->next;
            
            
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            
            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            
            
            ListNode* tmp = groupPrev->next;
            
           
            groupPrev->next = kth;
            
           
            groupPrev = tmp;
        }

        return dummy.next;
    }

private:
    
    ListNode* getKth(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};