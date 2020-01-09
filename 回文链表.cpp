class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next == NULL) break;
            fast = fast->next;
            slow = slow->next;
        }
        /*
        分析上面这个while循环，里面如果满足if条件，则slow的值不会改变，因此，可以将if写进while里面
        while(fast->next != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* ptr = slow->next;
        while(ptr->next != NULL){
            ListNode* temp = ptr->next;
            ptr->next = temp->next;
            temp->next = slow->next;
            slow->next = temp;
        }
        ListNode* par1 = head;
        ListNode* par2 = slow->next;
        do{
            if(par1->val != par2->val) return false;
            par1 = par1->next;
            par2 = par2->next;
        } while(par2 != NULL);
        return true;
        
    }
};
