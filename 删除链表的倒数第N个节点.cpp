class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        ListNode** ptr2 = &head;
        for(int i = 0; i < n; ++i){
            ptr1 = ptr1->next;
        }
        while(ptr1 != NULL){
            ptr1 = ptr1->next;
            ptr2 = &((*ptr2)->next);
        }
        ListNode* temp = (*ptr2)->next;
        delete (*ptr2);
        (*ptr2) = temp;
        return head;
    }
};
