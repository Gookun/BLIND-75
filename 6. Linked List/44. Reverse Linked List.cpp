//iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next =prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
//recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* newHead = head;
        if(head->next){
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = NULL;
        return newHead;
    }
};