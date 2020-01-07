//简单题，采用不同速度的指针，若快指针能追上慢指针，则证明有环。
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        while(ptr2 != NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr2 == NULL) return false;
            ptr2 = ptr2->next;
            if(ptr1 == ptr2) return true;
        }
        return false;
    }
};
