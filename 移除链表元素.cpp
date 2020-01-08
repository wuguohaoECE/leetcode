class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** ptr = &head;
        while(*ptr != NULL){
            if((*ptr)->val == val){
                ListNode* temp = (*ptr)->next;
                delete *ptr;
                *ptr = temp;
            }
            else{
                ptr = &((*ptr)->next);
            }
        }
        return head;
    }
};
