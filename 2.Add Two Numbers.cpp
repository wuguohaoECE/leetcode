//时间O(max(m,n)) 空间O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return Helper(l1, l2, 0);
    }
    ListNode* Helper(ListNode* l1, ListNode* l2, int adder){
        if(l1 == NULL && l2 == NULL && adder == 0) return NULL;
        int digit = adder;
        if(l1 != NULL) digit += l1->val;
        if(l2 != NULL) digit += l2->val;
        if(digit >= 10){
            digit -= 10;
            adder = 1;
        }
        else{
            adder = 0;
        }
        l1 = l1 != NULL ? l1->next : NULL;
        l2 = l2 != NULL ? l2->next : NULL;
        ListNode* newNode = new ListNode(digit);
        newNode->next = Helper(l1, l2, adder);
        return newNode;
    }
};
