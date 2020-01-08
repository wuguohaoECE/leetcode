class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ptr1 = head;
        if(ptr1 == NULL || ptr1->next == NULL || ptr1-> next->next == NULL) return head;
        ListNode** ptr2 = &ptr1->next->next;
        while(*ptr2 != NULL){
            ListNode* temp = (*ptr2)->next;
            (*ptr2)->next = ptr1->next;
            ptr1->next = *ptr2;
            *ptr2 = temp;
            if(temp == NULL) break;
            ptr2 = &(temp->next);
            ptr1 = ptr1->next;
        }
        return head;
    }
};
