class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy_head = new ListNode();
        dummy_head -> next = head;
        ListNode* fast = dummy_head;
        ListNode* slow = dummy_head;
        
        for(int i=0 ; i<n ;++i)
            fast =fast->next;
        while(fast->next != NULL){
            fast = fast ->next;
            slow = slow ->next;
        }
        slow->next = slow->next->next;
        return dummy_head->next;
    }
};