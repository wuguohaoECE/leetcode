class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l2->val < l1->val) swap(l1, l2);
        ListNode* ans = l1;
        while(l1->next != NULL && l1->next->val < l2->val){
            l1 = l1->next;
        }
        ListNode* l1next = l1->next;
        ListNode* l2next = l2->next;
        l1->next = l2;
        l2->next = mergeTwoLists(l1next, l2next);
        return ans;
    }
};
